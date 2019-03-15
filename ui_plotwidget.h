/********************************************************************************
** Form generated from reading UI file 'plotwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTWIDGET_H
#define UI_PLOTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDockWidget
{
public:
    QWidget *dockWidgetContents;
    QWidget *widget;

    void setupUi(QDockWidget *QDockWidget)
    {
        if (QDockWidget->objectName().isEmpty())
            QDockWidget->setObjectName(QStringLiteral("QDockWidget"));
        QDockWidget->resize(1127, 631);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        widget = new QWidget(dockWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 9, 1101, 591));
        QDockWidget->setWidget(dockWidgetContents);

        retranslateUi(QDockWidget);

        QMetaObject::connectSlotsByName(QDockWidget);
    } // setupUi

    void retranslateUi(QDockWidget *QDockWidget)
    {
        QDockWidget->setWindowTitle(QApplication::translate("QDockWidget", "DockWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QDockWidget: public Ui_QDockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTWIDGET_H
