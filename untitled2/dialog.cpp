#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "dialog1.h"
Dialog::Dialog(QWidget *parent, SparsedVector<int,int>* Seq, int Size) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    Length=Seq->GetLength();
    size=Size;
    seq=Seq;
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::resirvedText(QString str)
{
    ui->resirvedText->setText(str);
}




void Dialog::on_pushButton_clicked()
{
    if (size>seq->GetLength())
    {
        seq->Add(seq->GetLength(),ui->elem->text().toInt());
        Length++;
    }
    ui->elem->setText(" ");
    ui->resirvedText->setText(QString::number(this->size-this->Length));

}

void Dialog::on_pushButton_2_clicked()
{
    hide();
    Dialog1 *fm = new Dialog1(this,seq,seq->GetLength());
    fm->show();
}
