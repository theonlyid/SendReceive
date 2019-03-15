#include "frameprotocol.h"
#include <mainwindow.h>
#include <ui_mainwindow.h>


frameProtocol::frameProtocol()
{

    data_arrays.IRAmbient.reserve(1);
    data_arrays.IRLED.reserve(1);
    data_arrays.RedAmbient.reserve(1);
    data_arrays.RedLED.reserve(1);

    newDataAvailable = false;
    newLogEvt = false;

}


QByteArray frameProtocol::pack(QByteArray frameData)

{

    frameSize = frameProtocol::getByteSize(frameData); //Fetch size

    frameData.push_front(frameSize); // Add size to header

    frameData.push_back(checkSum(frameData)); // Calculate checksum

    frameData.push_front(SYNCBYTE); // Add SYNCBYTE

    return frameData; // Return encapsulated frame to main()
}



int frameProtocol::getByteSize(QByteArray frameData)
{
    int size = frameData.size();
    return size;

}


int frameProtocol::checkSum(QByteArray frameData)
{
    crc = 0;
    for(int l=frameData.length(); l>0; l--)
        crc ^= frameData[l];
    return crc;
}


void frameProtocol::unpack(QByteArray dataRecieved)
{
    qDebug() << endl << "Raw data recieved from serial port: " << endl<< dataRecieved.toHex();

    // Get Syncbyte

    int syncCount = dataRecieved.count(SYNCBYTE);  qDebug() << "Number of syncs found: " <<syncCount;

    // For each SYNCBYTE found

    int currentSync = 0;

    for(syncIterator = 0; syncIterator<syncCount; syncIterator++)   // For each sync in frame
    {

        syncIdx = dataRecieved.indexOf(SYNCBYTE, currentSync);  // Get the Sync idx

        // Byte processing starts here
        qDebug() << "Processing Byte " <<syncIterator+1 << " of " << syncCount;

        byteSize = dataRecieved[syncIdx+1];
        if(byteSize<=14)
        {

            qDebug() << "Bytesize: " << byteSize;

            chks = dataRecieved[syncIdx + byteSize + 2];

            myByte=0;

            for (int k=0; k<=byteSize; k++)
            {

                myByte[k]  = dataRecieved[syncIdx+k+1];
            }

            crc = checkSum(myByte);

            data_arrays.RedLED.clear();     data_arrays.RedLED.reserve(syncCount);
            data_arrays.RedAmbient.clear(); data_arrays.RedAmbient.reserve(syncCount);
            data_arrays.IRLED.clear();      data_arrays.IRLED.reserve(syncCount);
            data_arrays.IRAmbient.clear();  data_arrays.IRAmbient.reserve(syncCount);

            if(chks==crc)
           {
                qDebug()<< "Checksum correct";
                frameProtocol::processByte(myByte);

                currentSync = currentSync + byteSize + 3;
            }

            else
            {
                qDebug() << "Error in checksum";
                currentSync=currentSync+1;
            }
        }

    }


}

// Interpret unpacked data

void frameProtocol::processByte(QByteArray mybyte)
{

    pid_val = mybyte[1];
    cid_val = mybyte[2];
    cid_sub = mybyte[3];

     switch (pid_val)
    {

    case PID_SPO2:

        switch (cid_val)
        {
        case CID_SPO2_CONFIGURE_ACQUISITION:
            qDebug() << "Config command ";

            if(cid_sub==CID_ACK)
                qDebug() << "Acknowledged";

            if(cid_sub == CID_NACK)
                qDebug() << "Declined";

            break;

        case CID_SPO2_START_ACQUISITION:

            qDebug() << "Start Acq";

            if(cid_sub == CID_ACK)
                qDebug() << "Acknowledged";

            if(cid_sub==CID_NACK)
                qDebug() << "Declined";
            break;

        case CID_SPO2_STOP_ACQUISITION:

            qDebug() << "Stop Acq";

            if(cid_sub==CID_ACK)
                qDebug() << "Acknowledged";

            if(cid_sub==CID_NACK)
                qDebug() << "Declined";

            break;


        case EVENT_SPO2_RAW_DATA:

            qDebug() << "Byte is a data Frame" <<endl;

            QByteArray red_vals, red_ambient, ir_vals, ir_ambient;

            for(int j=0; j<3; j++)
            {
                red_vals[j] = mybyte[j+3];
                red_ambient[j] = mybyte[j+6];

                ir_vals[j] = mybyte[j+9];
                ir_ambient[j] = mybyte [j+12];
            }

            double redVals    = convertBytetoVolts(red_vals);
            double redAmbient = convertBytetoVolts(red_ambient);
            double irVals     = convertBytetoVolts(ir_vals);
            double irAmbient  = convertBytetoVolts(ir_ambient);


            if (!newDataAvailable)
                newDataAvailable = true;

            data_arrays.RedLED.push_back(redVals);
            data_arrays.RedAmbient.push_back(redAmbient);
            data_arrays.IRLED.push_back(irVals);
            data_arrays.IRAmbient.push_back(irAmbient);

        }
    }
}

double frameProtocol::convertBytetoVolts(QByteArray dataByte)
{
    // Reconstruct the data
    qint32 data_signed22bits = ((dataByte[0]&0x3F)<<16) + ((dataByte[1]&0xFF)<<8) + (dataByte[2]&0xFF);

    // Data is signed 22bits, convert it into a signed 32bits
    qint32 data_signed32bits = data_signed22bits;
    if (data_signed32bits&0x200000)                 // if data is negative (bit 22 == 1)
        data_signed32bits |= 0xFFC00000;            // then, 1-fill left, else, nothing to do

    // Volt = data * 1.2/2^21
    double dataVals = (data_signed32bits * 1.2 / 2097152); // 2^21 = 2097152
    return dataVals;
}

frameProtocol::DataArrays frameProtocol::getDataArrays()
{

    return data_arrays;
    newDataAvailable=false;

    data_arrays.IRAmbient.clear();
    data_arrays.IRLED.clear();
    data_arrays.RedAmbient.clear();
    data_arrays.RedLED.clear();
}

QString frameProtocol::getFrameLogs()
{
    return log;
    log.clear();
    newLogEvt=false;
}

bool frameProtocol::isDataAvailable()
{
    if(newDataAvailable)
        return true;
    else
        return false;
}
