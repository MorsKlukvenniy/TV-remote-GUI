#ifndef TV_REMOTE_H
#define TV_REMOTE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class tv_remote; }
QT_END_NAMESPACE

class tv_remote : public QMainWindow
{
    Q_OBJECT

public:
    tv_remote(QWidget *parent = nullptr);
    ~tv_remote();
    void channale_update();

private slots:
    void on_button_on_off_clicked();

    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_0_clicked();

    void on_button_return_clicked();

    void on_button_ch_up_clicked();

    void on_button_ch_down_clicked();

private:
    Ui::tv_remote *ui;
};
#endif // TV_REMOTE_H
