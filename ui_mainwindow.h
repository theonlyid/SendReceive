/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *customPlot;
    QCustomPlot *customPlot2;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QListWidget *listWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *selectButton;
    QGroupBox *groupBox_3;
    QPushButton *startButton;
    QPushButton *clearButton;
    QPushButton *Initialize;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QSpinBox *spinBox;
    QWidget *tab_2;
    QLineEdit *lineEdit_3;
    QPushButton *sendButton1;
    QPushButton *sendButton3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QPushButton *sendButton2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1090, 979);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 330, 1071, 301));
        customPlot2 = new QCustomPlot(centralWidget);
        customPlot2->setObjectName(QStringLiteral("customPlot2"));
        customPlot2->setGeometry(QRect(10, 680, 1071, 271));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 310, 60, 16));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 660, 60, 16));
        label_3->setFont(font);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 10, 471, 271));
        groupBox_2->setFont(font);
        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setEnabled(true);
        listWidget->setGeometry(QRect(10, 30, 451, 187));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(357, 187));
        listWidget->setFont(font);
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(230, 230, 104, 32));
        pushButton_2->setFont(font);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(350, 230, 105, 32));
        pushButton->setFont(font);
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 230, 139, 32));
        pushButton_4->setFont(font);
        selectButton = new QPushButton(groupBox_2);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setGeometry(QRect(140, 230, 80, 32));
        selectButton->setFont(font);
        listWidget->raise();
        pushButton_4->raise();
        selectButton->raise();
        pushButton_2->raise();
        pushButton->raise();
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(520, 10, 120, 271));
        groupBox_3->setFont(font);
        startButton = new QPushButton(groupBox_3);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setEnabled(false);
        startButton->setGeometry(QRect(10, 195, 101, 32));
        startButton->setFont(font);
        clearButton = new QPushButton(groupBox_3);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setEnabled(false);
        clearButton->setGeometry(QRect(10, 229, 101, 32));
        clearButton->setFont(font);
        Initialize = new QPushButton(groupBox_3);
        Initialize->setObjectName(QStringLiteral("Initialize"));
        Initialize->setGeometry(QRect(10, 161, 101, 32));
        Initialize->setFont(font);
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(true);
        checkBox->setGeometry(QRect(90, 310, 114, 20));
        checkBox->setFont(font);
        checkBox->setChecked(false);
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setEnabled(true);
        checkBox_2->setGeometry(QRect(203, 310, 97, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy1);
        checkBox_2->setFont(font);
        checkBox_2->setChecked(false);
        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setEnabled(true);
        checkBox_3->setGeometry(QRect(301, 310, 171, 20));
        checkBox_3->setFont(font);
        checkBox_3->setChecked(true);
        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(657, 301, 59, 24));
        doubleSpinBox->setFont(font);
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(1);
        doubleSpinBox->setMaximum(20);
        doubleSpinBox->setSingleStep(0.2);
        doubleSpinBox->setValue(10);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(521, 301, 128, 16));
        label->setFont(font);
        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(90, 660, 114, 20));
        checkBox_4->setFont(font);
        checkBox_4->setChecked(false);
        checkBox_6 = new QCheckBox(centralWidget);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setGeometry(QRect(301, 660, 171, 20));
        checkBox_6->setFont(font);
        checkBox_6->setChecked(true);
        checkBox_5 = new QCheckBox(centralWidget);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(203, 660, 97, 20));
        sizePolicy1.setHeightForWidth(checkBox_5->sizePolicy().hasHeightForWidth());
        checkBox_5->setSizePolicy(sizePolicy1);
        checkBox_5->setFont(font);
        checkBox_5->setChecked(false);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(650, 10, 431, 271));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        doubleSpinBox_2 = new QDoubleSpinBox(tab);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(160, 20, 68, 24));
        doubleSpinBox_2->setDecimals(1);
        doubleSpinBox_4 = new QDoubleSpinBox(tab);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(160, 100, 68, 24));
        doubleSpinBox_4->setDecimals(1);
        doubleSpinBox_5 = new QDoubleSpinBox(tab);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(160, 140, 68, 24));
        doubleSpinBox_5->setDecimals(1);
        spinBox = new QSpinBox(tab);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(160, 60, 71, 24));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 175, 301, 21));
        lineEdit_3->setFont(font);
        sendButton1 = new QPushButton(tab_2);
        sendButton1->setObjectName(QStringLiteral("sendButton1"));
        sendButton1->setGeometry(QRect(310, 36, 107, 32));
        sendButton1->setFont(font);
        sendButton3 = new QPushButton(tab_2);
        sendButton3->setObjectName(QStringLiteral("sendButton3"));
        sendButton3->setGeometry(QRect(310, 171, 107, 32));
        sendButton3->setFont(font);
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 105, 301, 21));
        lineEdit_2->setFont(font);
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 41, 301, 21));
        lineEdit->setFont(font);
        sendButton2 = new QPushButton(tab_2);
        sendButton2->setObjectName(QStringLiteral("sendButton2"));
        sendButton2->setGeometry(QRect(310, 100, 107, 32));
        sendButton2->setFont(font);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        checkBox->raise();
        checkBox_2->raise();
        checkBox_3->raise();
        doubleSpinBox->raise();
        label->raise();
        checkBox_4->raise();
        checkBox_6->raise();
        checkBox_5->raise();
        groupBox_3->raise();
        customPlot->raise();
        customPlot2->raise();
        label_3->raise();
        groupBox_2->raise();
        label_2->raise();
        tabWidget->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Red", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Infrared", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Configure serial device", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Open Port", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Close Port", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Refresh port list", Q_NULLPTR));
        selectButton->setText(QApplication::translate("MainWindow", "Select", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Start/Stop", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        Initialize->setText(QApplication::translate("MainWindow", "Initialize", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Ambient (blue)", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "LED (green)", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "Ambient corrected (red)", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "X-axis scroll width(s)", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("MainWindow", "Ambient (blue)", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("MainWindow", "Ambient corrected (red)", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("MainWindow", "LED (green)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        sendButton1->setText(QApplication::translate("MainWindow", "Send CMD", Q_NULLPTR));
        sendButton3->setText(QApplication::translate("MainWindow", "Send CMD", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Write entire frame with SYNCBYTE and crc (not checked currently)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lineEdit->setText(QApplication::translate("MainWindow", "5A07010103FF18020200", Q_NULLPTR));
        sendButton2->setText(QApplication::translate("MainWindow", "Send CMD", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
