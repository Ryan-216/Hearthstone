#include "arch.h"
#include <QtWidgets/QApplication>
using namespace std;


/*
* ����-->��ͼ-->����-->����Ԫ��
* 
* ��
* 
* 
* 
* arch�� �̳� QWidget ������Ϸ��ҳ��
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
