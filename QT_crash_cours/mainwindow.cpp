#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int firstNumb,secondNumb, result;


void MainWindow::on_button_plus_clicked()
{
    firstNumb= ui->txt_first_n->text().toInt();
    secondNumb= ui->txt_second_n->text().toInt();
    result= firstNumb+secondNumb;
    ui->txt_result->setText(QString::number(result));

}


void MainWindow::on_button_minus_clicked()
{
    firstNumb= ui->txt_first_n->text().toInt();
    secondNumb= ui->txt_second_n->text().toInt();
    result= firstNumb-secondNumb;
    ui->txt_result->setText(QString::number(result));

}


void MainWindow::on_button_devide_clicked()
{
    firstNumb= ui->txt_first_n->text().toInt();
    secondNumb= ui->txt_second_n->text().toInt();
    result= firstNumb/secondNumb;
    ui->txt_result->setText(QString::number(result));
}






void MainWindow::on_button_multiply_clicked()
{
    firstNumb= ui->txt_first_n->text().toInt();
    secondNumb= ui->txt_second_n->text().toInt();
    result= firstNumb*secondNumb;
    ui->txt_result->setText(QString::number(result));
}

