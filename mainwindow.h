#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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


private:
    Ui::MainWindow *ui;


};

//namespace {
	extern bool clicked;
//}

#endif // MAINWINDOW_H
