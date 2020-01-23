#include "tv_remote.h"
#include <QApplication>
#include <random>
#include <ctime>

int r = 0;

int main(int argc, char *argv[])
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> uid(0, 10);
    r = uid(mt);
    QApplication a(argc, argv);
    tv_remote w;
    w.show();
    return a.exec();
}
