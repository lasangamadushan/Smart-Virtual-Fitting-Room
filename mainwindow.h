#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pcl/visualization/pcl_visualizer.h> 
#include<pcl/io/ply_io.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
	void on_PushButton_clicked();

private slots:
	void on_browsebtn_clicked();

private slots:
	void on_nextbtn_clicked();

private slots:
	void on_prevbtn_clicked();

private slots:
	void on_importDressbtn_clicked();

private slots:
	void setDressImg(QString);

private slots:
	QString getImgPath(int);

private:
    Ui::MainWindow *ui;


};

//namespace {
	extern bool clicked;
	extern pcl::PointCloud<pcl::PointXYZRGBA>::Ptr dressCloud;
	extern boost::shared_ptr<pcl::visualization::PCLVisualizer> v;
//}

#endif // MAINWINDOW_H
