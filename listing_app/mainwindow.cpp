#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\todolist.txt");

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui-> list);
        ui->list->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);

    }

    file.close();

}
MainWindow::~MainWindow()
{
    delete ui;

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\todolist.txt");

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    for (int i = 0; i <ui->list->count()   ; ++i) {
        out<<ui->list->item(i)->text()<<"\n";
    }
    file.close();
}

void MainWindow::on_add_button_clicked()
{
    QListWidgetItem* item = new QListWidgetItem(ui->txt_task->text(), ui->list);
    ui->list->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->txt_task->clear();
    ui->txt_task->setFocus();
}


void MainWindow::on_del_button_clicked()
{
    QListWidgetItem* item = ui->list->takeItem(ui->list->currentRow());
    delete item;
}


void MainWindow::on_del_all_button_clicked()
{
    ui->list->clear();
}

