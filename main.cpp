#include "mainwindow.h"
#include <QApplication>
#include<emmc.h>
#include<QTextCodec>
#include <QObject>


void SetCodec(QApplication &app)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");//设置编码格式为UTF-8
    QTextCodec::setCodecForLocale(codec);//用于设置和对本地文件系统读写时候的默认编码格式。

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setMaximumSize(700,800);


           emmc w2; //跳转页面
           QObject::connect(&w,SIGNAL(showmain()),&w2,SLOT(recive()));

    return a.exec();
}
