#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtGui>
#include<QProcess>
#include<QFile>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QList>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void readoutput();

    void readerror();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_toolButton_clicked();

signals:
  void showmain();

private:
    Ui::MainWindow *ui;
    QProcess *p;
    //char FirstDriveFromMask (ULONG unitmask);
};


#endif // MAINWINDOW_H
