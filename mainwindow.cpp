#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	connect(ui->pushButton, SIGNAL(released()), this, SLOT(on_PushButton_clicked()));
	bool clicked = false;
	qDebug() << "ok";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_clicked() {
	QPushButton *button = (QPushButton*)sender();
	ui->label->setText("hello man");
	//clicked = true;
	qDebug() << "test";

}
