#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete chat;
}
void MainWindow::on_pushButton_clicked()
{
    chat=new Chat(ui->ip->toPlainText(),ui->port->toPlainText(),ui->nick->toPlainText());
    chat->show();
    this->hide();
}
