#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "dialog.h"
#include "dialog.cpp"
#include "dialog1.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix(":/resource/img/Ninja Turtles.png");
    int w=ui->label->width();
    int h=ui->label->height();
    ui->label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    w=ui->label_3->width();
    h=ui->label_3->height();
    QPixmap pix1(":/resource/img/Don.png");
    ui->label_3->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
    w=ui->label_4->width();
    h=ui->label_4->height();
    QPixmap pix2(":/resource/img/Michelangelo.png");
    ui->label_4->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
    w=ui->label_5->width();
    h=ui->label_5->height();
    QPixmap pix3(":/resource/img/Raf (1).png");
    ui->label_5->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::resirvedelem(QString str)
{
    elem=str;
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

        if(ui->SortSeq->isChecked()){
            ArraySequence<pair<int,int>>* Arrint=new ArraySequence<pair<int,int>>;

            this->Seq=new SparsedVector<int,int>(Arrint);


        }
        else
        {
            if(ui->IDict->isChecked()){

               this->Seq=new SparsedVector<int,int>(ui->size->text().toInt()/2);
            }

        }

        if(ui->notrand->isChecked())
        {


                int size=(ui->size->text()).toInt();
                Dialog *fm = new Dialog(this,Seq,size);
                connect(this, &MainWindow::sendText, fm, &Dialog::resirvedText);
                emit sendText(ui->size->text());

                fm->show();

        }
        else
        {
            for (int i = 0; i < ui->size->text().toInt(); i++)
            {
                            int k = 1 + rand() % 200;
                            if(k<100)
                                k=0;
                            Seq->Add(i,k);
            };
            Dialog1 *fm = new Dialog1(this,this->Seq,this->ui->size->text().toInt());
            fm->show();

        }





}


