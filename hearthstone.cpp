#include "hearthstone.h"
#include"card.h"
#include<qpainter.h>
#include"fightspace.h"
#include"handcard.h"
#include"cardlib.h"
#include"power.h"

hearthstone::hearthstone(QWidget *parent)
    : QWidget(parent)
{
    resize(1400, 950);
    QLabel* bg = new QLabel(this);
    bg->setFixedSize(1400, 950);
    bg->setPixmap(QPixmap(":/assert/bg_battle.png"));
    space = new fightspace(this);
    space->resize(1075, 735);
    space->move(163, 0);
    hand = new handcard(this);//hand无法显示
    hand->setParent(this);
    hand->resize(1400, 197);
    hand->move(0, 753);
  
    lib = new cardlib(this);
    lib->resize(62, 160);
    lib->move(1257, 475);
    pow = new power(this);
    pow->resize(150, 100);
    pow->move(13, 317);
    turnbutton = new QPushButton(this);
    turnbutton->resize(100, 100);
    turnbutton->move(1238, 317);
    turnbutton->setText("Your turn");
    optionbutton = new QPushButton(this);
    optionbutton->resize(100, 100);
    optionbutton->move(1300, 0);
    optionbutton->setText("Option");
    myturn = true;
    turns = 1;

    connect(hand, SIGNAL(costpower(int)),pow , SLOT(onhandcardcostpower(int)));

    //抽卡 测试完成
    connect(hand, SIGNAL(draw(int)),lib , SLOT(onhandcarddraw(int)));
    connect(lib, SIGNAL(sendcard(card *)),hand , SLOT(oncardlibsendcard(card *)));

    //测试未通过，信号不通畅
    connect(hand, SIGNAL(useminion(card *, QPoint )),space , SLOT(onhandcarduseminion(card * , QPoint )));
    connect(hand, SIGNAL(usedirspell(card * , QPoint * )), space, SLOT(onhandcardusedirspell(card * , QPoint )));
    connect(hand, SIGNAL(usenodirspell(card * )), space, SLOT(onhandcardusenodirspell(card * )));

    //
    connect(turnbutton, SIGNAL(clicked()),this , SLOT(switchturn()));
    connect(optionbutton, SIGNAL(clicked()),this , SLOT(openoption()));

    connect(hand, SIGNAL(send2main(QPoint , bool )), this, SLOT(onsend2main(QPoint, bool)));
}

void hearthstone::start_battle()
{
    hand->show();
    hand->drawcard(3);
}
hearthstone::~hearthstone()
{}

void hearthstone::enenmyact()
{
    //行动
    //交换回合

}


void hearthstone::switchturn()
{
    myturn = !myturn;
    turnbutton->setText(myturn ?"Your turn":"Enemy's turn");
    if (myturn)
    {
        hand->pow_add();
        hand->drawcard(1);
    }
    if (myturn == false) enenmyact();
    turns++;   
}

void hearthstone::openoption()
{
    qDebug() << "setting";
}

void hearthstone::onsend2main(QPoint p, bool start)
{
    if (start == true) {
        isdrawing = true;
        this->start = p;
    }
    else {
        this->end = p;
        update();
        repaint();
    }
}

void hearthstone::paintEvent(QPaintEvent* event)
{
    if (isdrawing) {
        QPainter painter(this);
        painter.drawLine(start, end);
    }
    
}

