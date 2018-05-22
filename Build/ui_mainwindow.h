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
#include <QtWidgets/QGroupBox>
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
    QLabel *dress_imglbl;
    QPushButton *nextbtn;
    QPushButton *prevbtn;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *importDressbtn;
    QGroupBox *groupBox;
    QLabel *label_2;
    QPushButton *browsebtn;
    QGroupBox *groupBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(350, 428);
        MainWindow->setMaximumSize(QSize(350, 720));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        dress_imglbl = new QLabel(centralwidget);
        dress_imglbl->setObjectName(QStringLiteral("dress_imglbl"));
        dress_imglbl->setGeometry(QRect(100, 90, 151, 161));
        dress_imglbl->setAutoFillBackground(false);
        dress_imglbl->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 2px solid #8f8f91;\n"
"border-radius: 12px;\n"
"min-width: 80px;"));
        nextbtn = new QPushButton(centralwidget);
        nextbtn->setObjectName(QStringLiteral("nextbtn"));
        nextbtn->setGeometry(QRect(260, 90, 35, 161));
        nextbtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	font-size: 12px;\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    min-width: 20px;\n"
"background: #D5D5D5;\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.3 rgba(255, 255, 255, 255), stop:1 rgba(213, 213, 213,255));\n"
"	\n"
"	\n"
"	border-left-color: rgb(67, 67, 67);\n"
"	border-bottom-color: rgb(67, 67, 67);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.3 rgba(255, 255, 255, 255), stop:1 rgba(213, 213, 213,255));\n"
"	position:relative;\n"
"	top:1px;\n"
"	border-left-color: none;\n"
"	border-bottom-color: none;\n"
"	border-top-color: none;\n"
"	border-right-color: none;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #D4D4D4;\n"
"	position:relative;\n"
"	top:1px;\n"
"}"));
        prevbtn = new QPushButton(centralwidget);
        prevbtn->setObjectName(QStringLiteral("prevbtn"));
        prevbtn->setGeometry(QRect(50, 90, 35, 161));
        prevbtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	font-size: 12px;\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    min-width: 20px;\n"
"background: #D5D5D5;\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.3 rgba(255, 255, 255, 255), stop:1 rgba(213, 213, 213,255));\n"
"	border-right-color: rgb(67, 67, 67);\n"
"	border-bottom-color: rgb(67, 67, 67);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.3 rgba(255, 255, 255, 255), stop:1 rgba(213, 213, 213,255));\n"
"	position:relative;\n"
"	top:1px;\n"
"	border-left-color: none;\n"
"	border-bottom-color: none;\n"
"	border-top-color: none;\n"
"	border-right-color: none;\n"
"}\n"
"QPushButton:hover {\n"
"   background-color: #D4D4D4;\n"
"	position:relative;\n"
"	top:1px;\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 310, 151, 31));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    border-radius: 6px;\n"
"    min-width: 80px;\n"
"font-size: 18px;\n"
"            color: #FFF;\n"
"            padding: 4px 22px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.5 rgba(94, 68, 133, 255), stop:1 rgba(126, 91, 178, 255));\n"
"border: 2px solid #FFF;\n"
"	border-top-color: rgb(50, 50, 50);\n"
"	border-bottom-color: rgb(255, 255, 255);\n"
"	border-left-color: rgb(255, 255, 255);\n"
"	border-right-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.5 rgba(126, 91, 178, 255), stop:1 rgba(94, 68, 133, 255));\n"
"	position:relative;\n"
"	top:1px;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.5 rgba(94, 68, 133, 255), stop:1 rgba(126, 91, 178, 255));\n"
"	position:relative;\n"
"	top:1px;\n"
"font-color:#D4D4D4;\n"
"	border-bottom-color: rgb(50, 50, 50);\n"
"	border-left-color: rgb(50, 50, 50);"
                        "\n"
"	border-right-color: rgb(50, 50, 50);\n"
"	border-top-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 65, 101, 16));
        label->setStyleSheet(QStringLiteral("font-size: 16px;"));
        importDressbtn = new QPushButton(centralwidget);
        importDressbtn->setObjectName(QStringLiteral("importDressbtn"));
        importDressbtn->setGeometry(QRect(100, 260, 151, 31));
        importDressbtn->setStyleSheet(QLatin1String("QPushButton {\n"
"    border-radius: 6px;\n"
"    min-width: 80px;\n"
"font-size: 18px;\n"
"            color: #FFF;\n"
"            padding: 4px 22px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.5 rgba(94, 68, 133, 255), stop:1 rgba(126, 91, 178, 255));\n"
"border: 2px solid #FFF;\n"
"	border-top-color: rgb(50, 50, 50);\n"
"	border-bottom-color: rgb(255, 255, 255);\n"
"	border-left-color: rgb(255, 255, 255);\n"
"	border-right-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.5 rgba(126, 91, 178, 255), stop:1 rgba(94, 68, 133, 255));\n"
"	position:relative;\n"
"	top:1px;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.5 rgba(94, 68, 133, 255), stop:1 rgba(126, 91, 178, 255));\n"
"	position:relative;\n"
"	top:1px;\n"
"font-color:#D4D4D4;\n"
"	border-bottom-color: rgb(50, 50, 50);\n"
"	border-left-color: rgb(50, 50, 50);"
                        "\n"
"	border-right-color: rgb(50, 50, 50);\n"
"	border-top-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(-10, 0, 361, 51));
        groupBox->setStyleSheet(QStringLiteral(" background: #5E4485;"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 15, 121, 20));
        label_2->setStyleSheet(QLatin1String("font-size: 16px;\n"
"            color: #FFF;"));
        browsebtn = new QPushButton(groupBox);
        browsebtn->setObjectName(QStringLiteral("browsebtn"));
        browsebtn->setGeometry(QRect(220, 10, 81, 31));
        browsebtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	font-size: 12px;\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    min-width: 20px;\n"
"background: #D5D5D5;\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.3 rgba(255, 255, 255, 255), stop:1 rgba(213, 213, 213,255));\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.3 rgba(255, 255, 255, 255), stop:1 rgba(213, 213, 213,255));\n"
"	position:relative;\n"
"	top:1px;\n"
"}\n"
"QPushButton:hover {\n"
"   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.3 rgba(213, 213, 213, 255), stop:1 rgba(255, 255, 255,255));\n"
"	position:relative;\n"
"	top:1px;\n"
"}"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 380, 361, 51));
        groupBox_2->setStyleSheet(QStringLiteral(" background: #5E4485;"));
        MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        dress_imglbl->raise();
        nextbtn->raise();
        prevbtn->raise();
        pushButton->raise();
        label->raise();
        importDressbtn->raise();
        groupBox_2->raise();
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
        dress_imglbl->setText(QString());
        nextbtn->setText(QApplication::translate("MainWindow", ">", Q_NULLPTR));
        prevbtn->setText(QApplication::translate("MainWindow", "<", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Dress me", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Select a Dress", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        importDressbtn->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        importDressbtn->setText(QApplication::translate("MainWindow", "Import Dress", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "Import a model", Q_NULLPTR));
        browsebtn->setText(QApplication::translate("MainWindow", "Browse", Q_NULLPTR));
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
