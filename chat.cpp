#include "chat.h"
#include "ui_chat.h"
Chat::Chat(QString ip, QString port, QString nick):
    ui(new Ui::Chat),nick(nick),ip(ip),port(port){
    ui->setupUi(this);
    ui->statusbar->hide();
    ui->menubar->hide();
    socket=new QTcpSocket(this);
    socket->connectToHost(ip,port.toUShort());
    if(socket->waitForConnected()){
        connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
        socket->flush();
        socket->waitForBytesWritten(3000);
    }
    else ui->chat->append("Connection lost");
}
Chat::~Chat(){
    delete ui;
    if(socket!=nullptr){
        if(socket->isOpen())socket->close();
        delete socket;
    }
}
void Chat::on_send_clicked(){
    QString fullmess=nick+": "+ui->mess->toPlainText();
    ui->chat->append(fullmess);
    ui->mess->clear();
    QByteArray mess=(fullmess+"\r\n").toLocal8Bit();
    const char * fullmes=mess.data();
    socket->write(fullmes);
    socket->flush();
    socket->waitForBytesWritten(2000);
}
void Chat::readyRead(){
    while(socket->canReadLine()){
        ui->chat->append(socket->readLine().trimmed());
    }
}
