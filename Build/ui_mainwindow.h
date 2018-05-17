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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *browsebtn;
    QLabel *label_2;
    QLabel *dress_imglbl;
    QPushButton *nextbtn;
    QPushButton *prevbtn;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *importDressbtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(350, 398);
        MainWindow->setMaximumSize(QSize(350, 720));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        browsebtn = new QPushButton(centralwidget);
        browsebtn->setObjectName(QStringLiteral("browsebtn"));
        browsebtn->setGeometry(QRect(190, 10, 75, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 10, 91, 16));
        dress_imglbl = new QLabel(centralwidget);
        dress_imglbl->setObjectName(QStringLiteral("dress_imglbl"));
        dress_imglbl->setGeometry(QRect(100, 90, 151, 161));
        dress_imglbl->setAutoFillBackground(false);
        dress_imglbl->setStyleSheet(QStringLiteral(" background-color: rgb(255, 255, 255)"));
        nextbtn = new QPushButton(centralwidget);
        nextbtn->setObjectName(QStringLiteral("nextbtn"));
        nextbtn->setGeometry(QRect(270, 90, 31, 161));
        prevbtn = new QPushButton(centralwidget);
        prevbtn->setObjectName(QStringLiteral("prevbtn"));
        prevbtn->setGeometry(QRect(50, 90, 31, 161));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 310, 151, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 60, 101, 16));
        importDressbtn = new QPushButton(centralwidget);
        importDressbtn->setObjectName(QStringLiteral("importDressbtn"));
        importDressbtn->setGeometry(QRect(100, 260, 151, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 350, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smart Virtual Fitting Room", Q_NULLPTR));
        browsebtn->setText(QApplication::translate("MainWindow", "Browse", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Import a model", Q_NULLPTR));
        dress_imglbl->setText(QString());
        nextbtn->setText(QApplication::translate("MainWindow", ">", Q_NULLPTR));
        prevbtn->setText(QApplication::translate("MainWindow", "<", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Dress me", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Select a Dress", Q_NULLPTR));
        importDressbtn->setText(QApplication::translate("MainWindow", "Import Dress", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
