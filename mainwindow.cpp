#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();
    connect(manager, QNetworkAccessManager::finished, this, MainWindow::replyFinished);
    ui->label_00->setStyleSheet(A_style);
    ui->label_01->setStyleSheet(A_style);
    ui->label_02->setStyleSheet(A_style);
    ui->label_03->setStyleSheet(A_style);
    ui->label_30->setStyleSheet(B_style);
    ui->label_31->setStyleSheet(B_style);
    ui->label_32->setStyleSheet(B_style);
    ui->label_33->setStyleSheet(B_style);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QByteArray byte = reply->readAll();
    QJsonDocument info = QJsonDocument::fromJson(byte);
    qDebug() << info;
    QString status = info.object()["status"].toString();
    QString end = info.object()["end"].toString();
    QString winer = info.object()["winer"].toString();
    QJsonArray chess = info.object()["chess"].toArray();

    if(status == "0"){
        return;
    }
    for(int i=0; i<chess.size(); i++){
        QString row = chess.at(i).toString();
        for(int j=0; j<row.size(); j++){
            QChar c = row.at(j);
            QString label_name = QString("label_%1%2").arg(i).arg(j);
            if(c == 'A'){
                this->findChild<QLabel*>(label_name)->setStyleSheet(A_style);
            }else if(c == 'B'){
                this->findChild<QLabel*>(label_name)->setStyleSheet(B_style);
            }else if(c == 'N'){
                this->findChild<QLabel*>(label_name)->setStyleSheet(N_style);
            }
        }
    }
    if(end == "1"){
        QMessageBox::information(this, "end", winer + " win!");
    }
}

void MainWindow::sendMsg(QPushButton *pb)
{
    QByteArray data = "operation=";
    data += pb->objectName().split("_")[1];
    QUrl url("http://localhost:8080/qt/chess");
    QNetworkRequest request;
    request.setUrl(url);
    data += "&player_id=A";
    manager->post(request, data);
}

void MainWindow::on_pushButton_1A_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_1B_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_1C_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_2A_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_2B_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_2C_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_3A_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_3B_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_3C_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_4A_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_4B_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_4C_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_T1_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_T2_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_T3_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_T4_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_M1_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_M2_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_M3_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_M4_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_D1_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_D2_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_D3_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}
void MainWindow::on_pushButton_D4_clicked(){
    sendMsg((QPushButton *)(this->sender()));
}

