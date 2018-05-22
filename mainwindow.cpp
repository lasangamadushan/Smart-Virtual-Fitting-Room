#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QPropertyAnimation>

int w;
int h;
QFileInfoList fileInfoList;
int length_imgList;
QString dressFileName;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
	w = ui->dress_imglbl->width();
	h = ui->dress_imglbl->height();

	QDir imgDir("data/images");
	QStringList filters;
	filters << "*.png" << "*.jpg" << "*.bmp";
	fileInfoList = imgDir.entryInfoList(filters, QDir::Files | QDir::NoDotAndDotDot);
	length_imgList = fileInfoList.length();

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
	clicked = true;
	qDebug() << "test";

}

void MainWindow::on_browsebtn_clicked() {
	//QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", tr("All Files (*.*)"));
	//qDebug() << filename;

}

int imageIndex = 0;
void MainWindow::on_nextbtn_clicked() {
	imageIndex++;
	qDebug() << length_imgList;

	if (imageIndex > length_imgList-1) {
		imageIndex = length_imgList-1;
	}
	setDressImg(getImgPath(imageIndex));
	QPropertyAnimation *anm = new QPropertyAnimation(ui->dress_imglbl,"geometry");
	anm->setDuration(2000);
	anm->setStartValue(10);

}


void MainWindow::on_prevbtn_clicked() {
	imageIndex--;
	if (imageIndex < 0) {
		imageIndex = 0;
	}
	
	setDressImg(getImgPath(imageIndex));
}


void MainWindow::setDressImg(QString imgpath) {
	QPixmap pix(imgpath);

	ui->dress_imglbl->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

QString MainWindow::getImgPath(int index) {
	qDebug() << fileInfoList.at(index).filePath();
	QString imgName = fileInfoList.at(index).fileName();
	size_t position = imgName.lastIndexOf(".");
	dressFileName = imgName.mid(0,position)+".ply";
	qDebug() << dressFileName;
	//QString imgPath = (QString)fileInfoList.at(1).path();
	return fileInfoList.at(index).filePath();
	
}


void MainWindow::on_importDressbtn_clicked() {
	v->removePointCloud("shirt");
	pcl::io::loadPLYFile("data/dresses/"+dressFileName.toStdString(), *dressCloud);
	v->addPointCloud<pcl::PointXYZRGBA>(dressCloud, "shirt");
}

