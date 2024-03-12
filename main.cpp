#include "arch.h"
#include <QtWidgets/QApplication>
using namespace std;


/*
* 窗口-->视图-->场景-->场景元素
* 
* 类
* 
* 玩家类 继承 QGraphicsPixmapItem
* 
* 卡牌类 继承 QGraphicsPixmapItem
* 
* arch类 继承 QWidget 调度游戏内页面
* 
* 视图类 继承 QGraphicsView
* 
* 场景类 继承 QGraphicsScene
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
