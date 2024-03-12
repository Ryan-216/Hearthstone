#include "BattleScene.h"


void BattleScene::battle()
{
	//初始抽牌
	draw_cards(hero_, 5);
	draw_cards(enemy_, 5);	
	draw_cards(enemy_, 1);

	
	connect(this->btn_end_of_turn, &QPushButton::clicked, [this]() {
		this->turn = false;
		update();
		});
	if (!turn)
	{
		for (auto it = hero_->hand_cards.begin(); it < cards_.end(); it++)
		{
			(*it)->status_ ++;
		}
	}
	//QObject::connect(this, &BattleScene::draw, this, &BattleScene::paint_cards);
	//我方回合
	
	//法力值+1

	//操作
}

void BattleScene::draw_cards(Hero* hero, int num)
{
	std::default_random_engine generator{ std::random_device{}() };
	std::shuffle(std::begin(cards_), std::end(cards_), generator);

	for (auto it = cards_.begin(); it < cards_.end()&& num > 0; it++)
	{
		hero->hand_cards.push_back(*it);
		
		cards_.erase(it);
		num--;
	}
	paint_cards(hero);
}

void BattleScene::paint_cards(Hero* hero)
{
	//0手牌，1战斗，2死亡
	int cards_num[3] = { 0 };
	int mid_width = width_ / 2;
	int mid_height = height_ / 2;
	int i = 0;

	for (BaseCard* card : hero->hand_cards) cards_num[card->status_]++;
	for (BaseCard* card : hero->hand_cards)
	{
		this->addWidget(card);
		if(card->status_ == 0) card->move(mid_width + (card->widght_ +10)* (i - cards_num[0] * 0.5), (hero == hero_ ? height_ - card->height_ : 0));
		if (card->status_ == 1) card->move(mid_width + (card->widght_ + 10) * (i - cards_num[1] * 0.5), (hero == hero_ ? mid_height : mid_height - card->height_));
		i++;
	}
}


//void BattleScene::mousePressEvent(QGraphicsSceneMouseEvent *mouse_event)
//{
//	
//	if (mouse_event->button()==Qt::LeftButton)
//	{
//
//	}
//	
//}
//
//void BattleScene::mouseMoveEvent(QGraphicsSceneMouseEvent* mouse_event)
//{
//
//	
//}
//void BattleScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse_event)
//{
//	//paint_cards();
//}







