#include "emmc.h"
#include "ui_emmc.h"
#include <mainwindow.h>
#include<QMessageBox>
#include<QFileDialog>


emmc::emmc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::emmc)
{
    ui->setupUi(this);
    p1=new QProcess(this);
     connect(p1, &QProcess::readyReadStandardOutput, this , &emmc::output);
     connect(p1 , &QProcess::readyReadStandardError, this , &emmc::error);



}

emmc::~emmc()
{
    delete ui;
}
void emmc::recive(){
     this->show();
}


void emmc::output()
{
    QString str = p1->readAllStandardOutput().data();
    ui->textBrowser->append(str);   //将输出信息读取到编辑框
}

void emmc::error()
{
    QMessageBox::warning(0, "警告！","输入错误，请重新输入。",p1->readAllStandardOutput());   //弹出信息框提示错误信息
}


void emmc::on_pushButton_2_clicked()//读取文件
{
    QFile file("C:/Users/admin/Desktop/xianshua/images/rawprogram0.xml");

    if(!file.open(QFile::ReadWrite | QFile::Text))
    QMessageBox::warning(0,"警告","文件无法打开");
    QTextStream in(&file);
    while(file.atEnd() == false)
    {
         ui->textBrowser->append(file.readLine());//一行一行读取内容
    }

    file.close();

}

void emmc::on_pushButton_3_clicked()//保存文件
{

    QString path = QFileDialog::getSaveFileName(this,
                                                       tr("Open xml File"),
                                                       ".",
                                                       tr("Text Files(*.xml)"));
           if(!path.isEmpty()) {
               QFile file(path);
               if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                   QMessageBox::warning(this, tr("Write File"),
                                              tr("Cannot open file:\n%1").arg(path));
                   return;
               }
               QTextStream out(&file);
                     auto tx= ui->textBrowser->toPlainText();
                     out<<tx;
               file.close();
           } else {
               QMessageBox::warning(this, tr("Path"),
                                    tr("You did not select any file."));
           }



}


void emmc::on_pushButton_clicked()//执行cmd指令
{
    QStringList commands;
    commands<<"/c"<<ui->lineEdit_2->text();
    p1->start("cmd",commands);
    p1->waitForStarted();
    p1->waitForFinished();

}

void emmc::on_pushButton_4_clicked()//清除textBrowser中的内容
{
ui->textBrowser->clear();
}
