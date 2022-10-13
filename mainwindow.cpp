#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<emmc.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p = new QProcess(this);

        connect(p , &QProcess::readyReadStandardOutput, this , &MainWindow::readoutput);
        connect(p , &QProcess::readyReadStandardError, this , &MainWindow::readerror);


        //端口号输出
        QList<QSerialPortInfo> serial_list = QSerialPortInfo::availablePorts();
        //这个函数将返回QList<QSerialPortInfo>类型的内容，返回内容是可用的串口信息
        int serialsize = serial_list.size();//返回内容的长度
        qDebug()<<serial_list.size();//打印长度
        for(int i = 0;i<serialsize;i++)
        {
             QString flag = serial_list.at(i).description();
             //description()的功能：类型转换，将QSerialPortInfo类型转换成QString类型，description()的功能
             qDebug()<<i<<flag;
             if(flag=="通信端口")
             {
                 ui->comboBox_2->addItem(serial_list.at(i).portName());//输出端口号
             }
             else{
                 ui->comboBox_2->addItem(serial_list.at(i).portName());//输出端口号
             }
        }

}

MainWindow::~MainWindow()
{
    delete ui;

   if(p) {
             p->close();
             p->waitForFinished();
       }
}


   void MainWindow::readoutput()
  {

   // QTextCodec* gbkCodec = QTextCodec::codecForName("GBK");
    QString str = p->readAllStandardOutput().data();
    ui->textBrowser->append(str);   //将输出信息读取到编辑框
       //ui->textBrowser->append("finished");
       //ui->textBrowser->append("end");

}

void MainWindow::readerror()
{
    QMessageBox::warning(0, "警告！","未连接，数值未返回。",p->readAllStandardOutput());   //弹出信息框提示错误信息
}


void MainWindow::on_pushButton_clicked()
{

    p->start("cmd");                      //启动终端(Windows下改为cmd)
    p->waitForStarted();                   //等待启动完成
    p->write("adb devices\n");    //查看是否连接
    p->write("adb shell service call iphonesubinfo 1\n");//IMEI
    p->write("adb shell getprop ro.build.version.release\n");//系统版本
    p->write("adb -d shell getprop ro.product.model\n");//设备型号


}


void MainWindow::on_toolButton_clicked()
{
    this->hide();
       emit showmain();
}
