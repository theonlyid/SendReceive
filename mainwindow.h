#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QByteArray>
#include <qdebug.h>
#include "frameprotocol.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void setPlot();

    void plotData(frameProtocol::DataArrays tsdata);

    ~MainWindow();


private slots:
    void on_startButton_clicked();

    void on_clearButton_clicked();

    void on_selectButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_Initialize_clicked();

    void on_pushButton_4_clicked();



    void on_sendButton1_clicked();

    void on_sendButton2_clicked();

    void on_sendButton3_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
