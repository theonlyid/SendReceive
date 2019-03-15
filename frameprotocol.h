#ifndef FRAMEPROTOCOL_H
#define FRAMEPROTOCOL_H
#include "QByteArray"
#include <qdebug.h>
#include <sharedprotocol.h>
#include <qstring.h>
#include <QVector>


class frameProtocol
{

public:

    // Variables:

    bool newDataAvailable;
    bool newLogEvt;

    struct DataArrays
    {
        QVector<double> RedLED;
        QVector<double> RedAmbient;
        QVector<double> IRLED;
        QVector<double> IRAmbient;
    };



    // Functions:
    frameProtocol();

    QByteArray pack(QByteArray frameData);

    void unpack(QByteArray dataRecieved); // for voltage only for now
    void processByte(QByteArray mybyte);

    double convertBytetoVolts(QByteArray dataByte);

    DataArrays getDataArrays();
    QString getFrameLogs();
    bool isDataAvailable();


protected:

private:
    int getByteSize(QByteArray data);
    int checkSum(QByteArray frameData);

    DataArrays data_arrays;

    QByteArray frameData; //data recieved from main window
    int frameSize;
    QByteArray myByte;

    QVector<double> timeseries;

    QString log;

    int syncIterator;
    int syncIdx;
    int byteSize;
    int crc;
    int chks;

    unsigned char pid_val;
    unsigned char cid_val;
    unsigned char cid_sub;

};

#endif // FRAMEPROTOCOL_H
