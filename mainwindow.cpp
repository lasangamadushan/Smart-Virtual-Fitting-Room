#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	connect(ui->pushButton, SIGNAL(released()), this, SLOT(on_PushButton_clicked()));
	connect(ui->browsebtn, SIGNAL(released()), this, SLOT(on_browsebtn_clicked()));
	bool clicked = false;
	qDebug() << "ok";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_clicked() {
	QPushButton *button = (QPushButton*)sender();
	ui->label->setText("look nice");
	clicked = true;
	qDebug() << "test";

}

void MainWindow::on_browsebtn_clicked() {
	QString filename = QFileDialog::getOpenFileName(
		this,
		tr("Open File"),
		"C://",
		"PLY File (*.ply);;"
	);
	qDebug() << filename;

}
