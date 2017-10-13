#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void replyFinished(QNetworkReply*);
    void on_pushButton_1A_clicked();
    void on_pushButton_1B_clicked();
    void on_pushButton_1C_clicked();
    void on_pushButton_2A_clicked();
    void on_pushButton_2B_clicked();
    void on_pushButton_2C_clicked();
    void on_pushButton_3A_clicked();
    void on_pushButton_3B_clicked();
    void on_pushButton_3C_clicked();
    void on_pushButton_4A_clicked();
    void on_pushButton_4B_clicked();
    void on_pushButton_4C_clicked();

    void on_pushButton_T1_clicked();
    void on_pushButton_T2_clicked();
    void on_pushButton_T3_clicked();
    void on_pushButton_T4_clicked();
    void on_pushButton_M1_clicked();
    void on_pushButton_M2_clicked();
    void on_pushButton_M3_clicked();
    void on_pushButton_M4_clicked();
    void on_pushButton_D1_clicked();
    void on_pushButton_D2_clicked();
    void on_pushButton_D3_clicked();
    void on_pushButton_D4_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    void sendMsg(QPushButton *pb);
    const QString A_style = "background-color: red; border-radius:15px;";
    const QString B_style = "background-color: blue; border-radius:15px;";
    const QString N_style = "background-color: transparent; border-radius:15px;";
};

#endif // MAINWINDOW_H
