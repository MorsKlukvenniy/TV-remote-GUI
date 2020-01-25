#include "tv_remote.h"
#include "ui_tv_remote.h"
#include <fstream>

int on_off = 0;
int curr_channel = 1;
int last_channel = 1;
int counter = 0;
int counter_2 = 0;
std::ofstream fout;
extern int r;

tv_remote::tv_remote(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tv_remote)
{
    ui->setupUi(this);
}

tv_remote::~tv_remote()
{
    delete ui;
}

void tv_remote::channale_update()
{
    if (on_off)
    {
        switch (curr_channel)
        {
        case 1:
            ui->current_channel->setText("Первый канал");
            break;
        case 2:
            ui->current_channel->setText("Россия 1");
            break;
        case 3:
            ui->current_channel->setText("ТВ3");
            break;
        case 4:
            ui->current_channel->setText("НТВ");
            break;
        case 5:
            ui->current_channel->setText("СТС");
            break;
        case 6:
            ui->current_channel->setText("МатчТВ");
            break;
        case 7:
            ui->current_channel->setText("ТНТ");
            break;
        case 8:
            ui->current_channel->setText("Россия К");
            break;
        default:
            ui->current_channel->setText("...");
            break;
        }
    }
    else
    {
        ui->current_channel->setText("");
    }
    if (counter > 25 + r)
    {
        if (counter_2 % 10 == 0)
        {
            fout.open("replay.txt", std::ios_base::app);
            ui->button_on_off->move(ui->button_on_off->x() + 3 + (counter_2 / 2), ui->button_on_off->y());
            fout << "counter = " << counter << "\tbutton x = " << ui->button_on_off->x() << std::endl;
            fout.close();
        }
        counter_2++;
    }
    if (counter == 0)
    {
        fout.open("replay.txt");
        fout << "initial position: button x = " <<  ui->button_on_off->x() << std::endl;
        fout.close();
    }
}

void tv_remote::on_button_on_off_clicked()
{
    on_off = !on_off;
    channale_update();
    counter++;
}

void tv_remote::on_pushButton_1_clicked()
{
    last_channel = curr_channel;
    curr_channel = 1;
    channale_update();
    counter++;
}
void tv_remote::on_pushButton_2_clicked()
{
    last_channel = curr_channel;
    curr_channel = 2;
    channale_update();
    counter++;
}
void tv_remote::on_pushButton_3_clicked()
{
    last_channel = curr_channel;
    curr_channel = 3;
    channale_update();
    counter++;
}
void tv_remote::on_pushButton_4_clicked()
{
    last_channel = curr_channel;
    curr_channel = 4;
    channale_update();
    counter++;
}
void tv_remote::on_pushButton_5_clicked()
{
    last_channel = curr_channel;
    curr_channel = 5;
    channale_update();
    counter++;
}
void tv_remote::on_pushButton_6_clicked()
{
    last_channel = curr_channel;
    curr_channel = 6;
    channale_update();
    counter++;
}
void tv_remote::on_pushButton_7_clicked()
{
    last_channel = curr_channel;
    curr_channel = 7;
    channale_update();
    counter++;
}
void tv_remote::on_pushButton_8_clicked()
{
    last_channel = curr_channel;
    curr_channel = 8;
    channale_update();
    counter++;
}
void tv_remote::on_pushButton_9_clicked()
{
    last_channel = curr_channel;
    curr_channel = 9;
    channale_update();
    counter++;
}
void tv_remote::on_pushButton_0_clicked()
{
    last_channel = curr_channel;
    curr_channel = 0;
    channale_update();
    counter++;
}


void tv_remote::on_button_return_clicked()
{
    int temp = last_channel;
    last_channel = curr_channel;
    curr_channel = temp;
    channale_update();
    counter++;
}

void tv_remote::on_button_ch_up_clicked()
{
    last_channel = curr_channel;
    curr_channel++;
    curr_channel %= 10;
    channale_update();
    counter++;
}

void tv_remote::on_button_ch_down_clicked()
{
    last_channel = curr_channel;
    curr_channel--;
    if (curr_channel < 0)
        curr_channel = 10;
    channale_update();
    counter++;
}
