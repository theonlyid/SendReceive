#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frameprotocol.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include "qcustomplot.h"

QSerialPort *serial;
frameProtocol *frame = new frameProtocol;


QByteArray dataFrameRecieved;
qint64 incomingFrameSize;

int StopState = 0;
frameProtocol::DataArrays datas;

QT_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    ui->listWidget->clear();
    QString description;
    QString manufacturer;
    QString serialNumber;

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : "blankString")
             << (!manufacturer.isEmpty() ? manufacturer : "blankString")
             << (!serialNumber.isEmpty() ? serialNumber : "blankString")
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : "blankString")
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : "blankString");

        ui->listWidget->addItem(info.portName());
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

// NOTE: Start button

void MainWindow::on_startButton_clicked()
{

    QElapsedTimer CodeTimer;
    CodeTimer.start();


    StopState=0;

    //ui->groupBox->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->clearButton->setEnabled(true);

    ui->statusBar->setWindowTitle("Recording");

    QByteArray frameToSend = 0x00;
    //TODO Anayze time


    // Create the initialization code
    frameToSend[0] = SYNCBYTE;
    frameToSend[1] = 0x02;
    frameToSend[2] = 0x01;
    frameToSend[3] = 0x02;
    frameToSend[4] = 0x03;

    serial->write(frameToSend);

    MainWindow::setPlot();

    while (StopState==0)
    {
        CodeTimer.restart(); qDebug() << "Timer intialized";
        qDebug() << "Acquisition started at: " << CodeTimer.nsecsElapsed()/1000.0;

        qDebug() << "Reading port at: " << CodeTimer.nsecsElapsed()/1000.0;
        serial->waitForReadyRead(1000);

        qDebug() << "Read signal received at : " << CodeTimer.nsecsElapsed()/1000.0;
        dataFrameRecieved = serial->readAll();
        qDebug() << "Data recieved at: " << CodeTimer.nsecsElapsed()/1000.0;

        frame->unpack(dataFrameRecieved);
        qDebug() << "Data unpacked at: " << CodeTimer.nsecsElapsed()/1000.0;

        if(bool dataAvail = frame->isDataAvailable())
        {
            datas = frame->getDataArrays();


            qDebug() << "Plotting started at: " << CodeTimer.nsecsElapsed()/1000;
            MainWindow::plotData(datas);
            qDebug() << "Plotting finished at: " << CodeTimer.nsecsElapsed()/1000.0 <<endl <<endl;
        }

        QApplication::processEvents();
    }
}



// NOTE: Stop Button Press:

void MainWindow::on_clearButton_clicked()
{

    ui->clearButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    //ui->groupBox->setEnabled(true);

    if(StopState==0)
    {
        QByteArray frameToSend = 0x00;

        // Create the initialization code
        frameToSend[0] = SYNCBYTE;
        frameToSend[1] = 0x02;
        frameToSend[2] = 0x01;
        frameToSend[3] = 0x03;
        frameToSend[4] = 0x02;

        serial->write(frameToSend);
        qDebug() << frameToSend;

        dataFrameRecieved = serial->readAll();

        ui->customPlot->clearGraphs();
        ui->customPlot2->clearGraphs();

        QApplication::processEvents();


        StopState=1;

    }
}

// NOTE: Select Serial Device:

void MainWindow::on_selectButton_clicked()
{

    QString currentPort = ui->listWidget->currentItem()->text();

    serial = new QSerialPort(this);
    serial->setPortName(currentPort);
    //    ui->textBrowser->setText(currentPort);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);

    ui->pushButton_2->setEnabled(true);

    qDebug() << "Connected to: " << serial->portName() <<endl;

}


// NOTE: Open Port

void MainWindow::on_pushButton_2_clicked()
{

   //ui->groupBox->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(true);

    if(!serial->open(QIODevice::ReadWrite))
    {
        serial->open(QIODevice::ReadWrite);
        serial->flush();
    }
    qDebug() << "portOpen" << endl;


}

// NOTE: Close port

// FIXME: Crashes when clicked without opening port

void MainWindow::on_pushButton_clicked()
{
    if(serial->isOpen())
    {

        if(StopState==0);
        on_clearButton_clicked(); //NOTE: Added to test
        serial->flush();
        serial->close();
    }

    //ui->groupBox->setEnabled(false);

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);

    qDebug() << "Port closed" << endl;

}


// NOTE: Initialize

void MainWindow::on_Initialize_clicked()
{

    if(serial->bytesAvailable())
        QByteArray junk = serial->readAll(); //Dump all pending serial data to junk

    // Initialize Byte
    QByteArray frameToSend = 0x00;

    // Create the initialization code NOTE: Currently hardcoded!

    frameToSend[0] = SYNCBYTE;
    frameToSend[1] = 0x07;
    frameToSend[2] = frameToSend[3] = 0x01;
    frameToSend[4] = 0x02;
    frameToSend[5] = 0x58;
    frameToSend[6] = 0x12;
    frameToSend[7] = 0x01;
    frameToSend[8] = 0x01;
    frameToSend[9] = 0x00;
    

    serial->write(frameToSend);
    qDebug() << frameToSend <<endl;

    serial->waitForReadyRead(100);
    QByteArray dataFrameRecieved = serial->readAll();
    frame->unpack(dataFrameRecieved);

    ui->startButton->setEnabled(true);
    ui->clearButton->setEnabled(true);


}


// NOTE: Refresh port list

void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget->clear();
    QString description;
    QString manufacturer;
    QString serialNumber;

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : "blankString")
             << (!manufacturer.isEmpty() ? manufacturer : "blankString")
             << (!serialNumber.isEmpty() ? serialNumber : "blankString")
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : "blankString")
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : "blankString");

        ui->listWidget->addItem(info.portName());
    }

}

// Set up plot
void MainWindow::setPlot()
{
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");

    // Initialize plot1: upper plot
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(Qt::green));
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setPen(QPen(Qt::red));

    ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(-2, 2);
    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // Initialize plot2: lower plot
    ui->customPlot2->addGraph();
    ui->customPlot2->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot2->addGraph();
    ui->customPlot2->graph(1)->setPen(QPen(Qt::green));
    ui->customPlot2->addGraph();
    ui->customPlot2->graph(2)->setPen(QPen(Qt::red));

    ui->customPlot2->xAxis->setTicker(timeTicker);
    ui->customPlot2->axisRect()->setupFullAxesBox();
    ui->customPlot2->yAxis->setRange(-2, 2);
    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->customPlot2->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot2->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot2->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot2->yAxis2, SLOT(setRange(QCPRange)));

}

void MainWindow::plotData(frameProtocol::DataArrays tsdata)

{

    static QTime time(QTime::currentTime());

    double key = 0;
    // add data to lines:
    for(int i=0; i<tsdata.IRAmbient.length(); i++)
    {
        double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
        if(ui->checkBox_4->isChecked())
            ui->customPlot2->graph(0)->addData(key, tsdata.IRAmbient[i]);
        if(ui->checkBox_5->isChecked())
            ui->customPlot2->graph(1)->addData(key, tsdata.IRLED[i]);
        if(ui->checkBox_6->isChecked())
            ui->customPlot2->graph(2)->addData(key, tsdata.IRLED[i] - tsdata.IRAmbient[i]);
        ui->customPlot2->xAxis->setRange(key, ui->doubleSpinBox->value(), Qt::AlignRight);
        ui->customPlot2->replot();
        ui->customPlot2->rescaleAxes();


        if(ui->checkBox->isChecked())
            ui->customPlot->graph(0)->addData(key, tsdata.RedAmbient[i]);
        if(ui->checkBox_2->isChecked())
            ui->customPlot->graph(1)->addData(key, tsdata.RedLED[i]);
        if(ui->checkBox_3->isChecked())
            ui->customPlot->graph(2)->addData(key, tsdata.RedLED[i] - tsdata.RedAmbient[i]);

        ui->customPlot->xAxis->setRange(key, ui->doubleSpinBox->value(), Qt::AlignRight);
        ui->customPlot->replot();
        ui->customPlot->rescaleAxes();
    }


}


//FIXME: Conversion not working

void MainWindow::on_sendButton1_clicked()
{
    QString myString = ui->lineEdit->text();

    QByteArray array2 = QByteArray::fromHex(myString.toLatin1());

    // QByteArray packet = frame->pack(array2);

    serial->write(array2);
    serial->waitForReadyRead();

    QByteArray response = serial->readAll();
    frame->unpack(response);
}

void MainWindow::on_sendButton2_clicked()
{
    QString myString = ui->lineEdit_2->text();

    QByteArray array2 = QByteArray::fromHex(myString.toLatin1());

    // QByteArray packet = frame->pack(array2);

    serial->write(array2);
    serial->waitForReadyRead();

    QByteArray response = serial->readAll();
    frame->unpack(response);
}

void MainWindow::on_sendButton3_clicked()
{
    QString myString = ui->lineEdit_3->text();

    QByteArray array2 = QByteArray::fromHex(myString.toLatin1());

    // QByteArray packet = frame->pack(array2);

    serial->write(array2);
    serial->waitForReadyRead();

    QByteArray response = serial->readAll();
    frame->unpack(response);
}
