#include "arch.h"
#include <QtWidgets/QApplication>
using namespace std;


/*
* 窗口-->视图-->场景-->场景元素
* 
* 类
* 
* 
* 
* arch类 继承 QWidget 调度游戏内页面
* 
* 
* 
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    arch game;
    game.start();
    return a.exec();
}
