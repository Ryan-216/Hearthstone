#include "cardlib.h"
#include <cstdlib>
#include "card.h"

cardlib::cardlib(QWidget* parent):label(parent)
{
    resize(62, 160);

    //添加卡牌资源
    for (int i = 0; i < 40; i++)
    {
        if (i < 20)
        {
            card* c = new card;
            minionlib.push_back(c);
            lib.push_back(c);
        }
        else
        {
            card* c = new card;
            spelllib.push_back(c);
            lib.push_back(c);
        }

    }

}

card* cardlib::randomcard()
{
    int a = 0, b = 40;
    int i = (rand() % (b - a)) + a;
    return lib[i];
}

card* cardlib::randomminion()
{
    int a = 0, b = 40;
    int i = (rand() % (b - a)) + a;
    return minionlib[i];
}

card* cardlib::randomspell()
{
    int a = 0, b = 40;
    int i = (rand() % (b - a)) + a;
    return spelllib[i];
}

void cardlib::onhandcarddraw(int num)
{
    qDebug() << "onhandcarddraw";
    for (int i = 0; i < num; i++)
    {
        emit sendcard(randomcard());
    }
}