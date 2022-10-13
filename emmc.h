#ifndef EMMC_H
#define EMMC_H

#include <QWidget>
#include<QMenu>
#include <QStandardItemModel>
#include <QAction>
#include <QTableWidget>
#include<QProcess>
#include<QDialog>
#include <QXmlStreamReader>
#include <QFileInfo>


namespace Ui {
class emmc;
}

class emmc : public QWidget
{
    Q_OBJECT

public:
    explicit emmc(QWidget *parent = nullptr);
    ~emmc();
    int writeXml();
    int readXml();

private:
    Ui::emmc *ui;
    QProcess *p1;

    void parseUserInformation();
        QString getValue(const QString &name);
        QString getAttribute(const QString &name);
        QString fileName;
        QXmlStreamReader *reader;





private  slots:
    void recive();
    void on_pushButton_2_clicked();//保存
    void on_pushButton_3_clicked();//读取
    void on_pushButton_clicked();//执行指令
    void output();
    void error();
    void on_pushButton_4_clicked();
};

#endif // EMMC_H
