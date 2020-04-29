#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "QDebug"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tramas->hide();
    ui->label->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionopen_triggered()
{
//limpia la ventana para la insercion de un nuevo archivo si almenos ya hay uno
if(accion==1)
{
ui->plainTextEdit->clear();
ui->plainTextEdit_2->clear();
accion=0;
}
//lectura del archivo
filename = QFileDialog::getOpenFileName(this,"TextEditor - Open file","/home/documento","Text Files (*.txt);;All Files (*.*)");
if(!filename.isEmpty())
{
    QFile file(filename);
     if(file.open(QFile::ReadOnly))
     {
       ui->plainTextEdit->setPlainText(file.readAll());
       accion=1;
     }
     else
     {
       QMessageBox::warning(
                this,
                   "TextEditor",
                   tr("no se pude leer el archivo")
                   .arg(filename)
                   .arg(file.errorString())
                   );
     }
}

}


void MainWindow::on_pushButton_clicked()
{
int nTramas=0;
if(accion)
{
QFile file(filename);
QFile resultado("C:/Users/candido/Fer/Programas"+QString::number(numeroF)+".txt");
resultado.open(QIODevice::Append);
if(file.open(QIODevice::ReadWrite))
{
QTextStream in(&file);
QTextStream le(&resultado);
while(!in.atEnd())
   {
    QString line = in.read(100);
    le<<line<<endl<<endl;
    nTramas+=1;
   }
 }
file.close();
 resultado.close();
//lectura del nuevo archivo formateado
   resultado.open(QIODevice::ReadOnly);
   ui->plainTextEdit_2->setPlainText(resultado.readAll());
   ui->tramas->setText("Numero de tramas: "+QString::number(nTramas));
   ui->tramas->show();
   numeroF+=1;
}
else
{
     QMessageBox::warning(this,"Error",tr("Seleccione primero un  archivo"));
}

}

void MainWindow::on_pushButton_2_clicked()
{

   if(accion==1)
   {
    QFile file(filename);
    int n=0;
    if(file.open(QIODevice::ReadWrite))
    {
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        n+=line.length();
        qDebug()<<QString::number(n)+"-";
    }
    ui->label->show();
     ui->label->setText("Numero de caracteres: "+QString::number(n));
    }
    file.close();
    }
   else
   {
       QMessageBox::warning(this,"Error",tr("Seleccione primero un  archivo"));
   }
}


