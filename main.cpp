#include "arch.h"
#include <QtWidgets/QApplication>
using namespace std;


/*
* ����-->��ͼ-->����-->����Ԫ��
* 
* ��
* 
* ����� �̳� QGraphicsPixmapItem
* 
* ������ �̳� QGraphicsPixmapItem
* 
* arch�� �̳� QWidget ������Ϸ��ҳ��
* 
* ��ͼ�� �̳� QGraphicsView
* 
* ������ �̳� QGraphicsScene
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
