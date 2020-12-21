#include "dialog1.h"
#include "ui_dialog1.h"
#include <QPixmap>

#include<chrono>
Dialog1::Dialog1(QWidget *parent,SparsedVector<int,int>* Seq,int Size) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    size=Size;
    seq=Seq;

    ui->setupUi(this);
    QPixmap pix(":/resource/img/Leo.png");
    int w=ui->label->width();
    int h=ui->label->height();

    ui->label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));




}

Dialog1::~Dialog1()
{
    delete ui;
}


void Dialog1::on_pushButton_clicked()
{

        QString str2;

        if(seq->ContainsKey(this->ui->Enter->text().toInt()))
        {
            str2=(QString::number(seq->Get(this->ui->Enter->text().toInt())));
        }
        else
        {
            str2="there is no Value" ;
        }
        this->ui->Out->setText(str2);



}

void Dialog1::on_pushButton_2_clicked()
{
    auto start = std::chrono::system_clock::now();
    QString str1;
    for(int i=0;i<size;i++)
    {
        if(seq->ContainsKey(i))
        {
            QString index=QString::number(i);
            str1=QString(str1)+" "+"{"+index+" "+(QString::number(seq->Get(i)))+"}";
        }

    }


    ui->textEdit->setText(str1);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    double time=elapsed.count();
    QString str = QString::number(time);
    ui->time->setText(str);

}
