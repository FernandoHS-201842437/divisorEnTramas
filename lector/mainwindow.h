#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionopen_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString filename;
    //0 si ningun archivo a sido cargado
    bool accion=0;
    //mantiene el flujo de creacion de archivos para que no se realice repeticion de archivos, despues del fin de la sesion se pierde el contador
    int numeroF=0;
};
#endif // MAINWINDOW_H
