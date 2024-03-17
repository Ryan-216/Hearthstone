#include "cardlib.h"
#include <cstdlib>

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
    for (int i = 0; i < num; i++)
    {
        emit sendcard(randomcard());
    }
}