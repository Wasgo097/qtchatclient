#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include <QTcpSocket>
namespace Ui {
class Chat;
}
class Chat : public QMainWindow{
    Q_OBJECT
public:
    explicit Chat(QString ip,QString port,QString nick);
    ~Chat();
private slots:
    void on_send_clicked();
    void readyRead();
private:
    Ui::Chat *ui;
    QString nick{""};
    QString ip{""};
    QString port{""};
    QTcpSocket * socket{nullptr};
};

#endif // CHAT_H
