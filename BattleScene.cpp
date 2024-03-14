#include "BattleScene.h"


void BattleScene::battle()
{
	//初始抽牌
	draw_cards(hero_, 5);
	draw_cards(enemy_, 5);	
	paint_text(hero_);
	paint_text(enemy_);

	timer_ = new QTimer();
	timer_->start(20);	
	connect(timer_, &QTimer::timeout, [this]() {
		this->fake_mouse();
		if (mouse_ == -1)
		{
			manage_attack();
			paint_all();			
		}
		});
	
	connect(this->btn_end_of_turn, &QPushButton::clicked,this, &BattleScene::turn_change);
	
}

void BattleScene::manage_attack()
{
	BaseCard* attacker = new BaseCard;
	if (turn)
	{
		for (auto it = hero_->hand_cards.begin(); it < hero_->hand_cards.end(); it++)
		{
			if ((*it)->status_ == 1 && (*it)->isDragging)	attacker = (*it);
		}
		for (auto it = enemy_->hand_cards.begin(); it < enemy_->hand_cards.end(); it++)
		{
			if ((*it)->status_ == 1)
			{
				if (mouse_pos.x() - (*it)->pos().x() <= (*it)->widght_ && mouse_pos.x() - (*it)->pos().x() >= 0 &&
					mouse_pos.y() - (*it)->pos().y() <= (*it)->height_ && mouse_pos.y() - (*it)->pos().y() >= 0)
				{
					qDebug() << "attack";
					attacker->Attack(*it);
					attacker->Death();
					(*it)->Death();
				}								
			};
		}	
	}
	else
	{
		for (auto it = enemy_->hand_cards.begin(); it < enemy_->hand_cards.end(); it++)
		{
			if ((*it)->status_ == 1 && (*it)->isDragging)	attacker = (*it);
		}
		for (auto it = hero_->hand_cards.begin(); it < hero_->hand_cards.end(); it++)
		{
			if ((*it)->status_ == 1)
			{
				if (mouse_pos.x() - (*it)->pos().x() <= (*it)->widght_ && mouse_pos.x() - (*it)->pos().x() >= 0 &&
					mouse_pos.y() - (*it)->pos().y() <= (*it)->height_ && mouse_pos.y() - (*it)->pos().y() >= 0)
				{
					attacker->Attack(*it);
					attacker->Death();
					(*it)->Death();
				}
			};
		}
	}
}

void  BattleScene::fake_mouse()
{
	if (this->mouseGrabberItem() != nullptr)
	{
		mouse_ = 1;
		mouse_pos = this->mouseGrabberItem()->scenePos();
	}
	else if (mouse_ == 1 && this->mouseGrabberItem() == nullptr)
	{
		mouse_ = -1;	
	}
	else mouse_ = 0;
}

void BattleScene::turn_change()
{
	//true 我方 false 敌方
	turn = !turn;
	for (auto it = hero_->hand_cards.begin(); it < hero_->hand_cards.end(); it++)
	{
		if ((*it)->status_ == 0) (*it)->allow_click_ = turn;//设置为是否移动
	}
	btn_end_of_turn->setText(turn ? "Your Turn" : "Enemy's Turn");
	draw_cards(turn ? hero_ : enemy_, 1);
	if (turn)
	{
		hero_->spell_fresh();
		paint_text(hero_);
	}
	else
	{
		enemy_->spell_fresh();
		paint_text(enemy_);
	}
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

void BattleScene::paint_text(Hero* hero)
{
	int mid_width = width_ / 2;
	QString text_hero = QString("HP: %1, MSP: %2, RSP: %3").arg(hero_->blood_).arg(hero_->max_spell).arg(hero_->remain_spell_);
	QString text_enemy = QString("HP: %1, MSP: %2, RSP: %3").arg(enemy_->blood_).arg(enemy_->max_spell).arg(enemy_->remain_spell_);
	hero_status->setText(text_hero);
	hero_status->resize(150,30);
	hero_status->move(mid_width - hero_status->width() * 0.5, 450);

	enemy_status->setText(text_enemy);
	enemy_status->resize(150, 30);
	enemy_status->move(mid_width - enemy_status->width() * 0.5, 150);
}

void  BattleScene::paint_all()
{
	paint_cards(enemy_);
	paint_cards(hero_);	
}

void BattleScene::paint_cards(Hero* hero)
{
	
	//0手牌，1战斗，2死亡
	int cards_num[3] = { 0 };
	int mid_width = width_ / 2;
	int mid_height = height_ / 2;
	int i = 0, j = 0;

	for (BaseCard* card : hero->hand_cards) cards_num[card->status_]++;
	for (BaseCard* card : hero->hand_cards)
	{		
		if (!card->isDragging)
		{
			this->addWidget(card);
			if (card->status_ == 0)
			{
				card->move(mid_width + (card->widght_ + 10) * (i - cards_num[0] * 0.5), (hero == hero_ ? height_ - card->height_ : 0));
				i++;
			}
			if (card->status_ == 1)
			{
				card->move(mid_width + (card->widght_ + 10) * (j - cards_num[1] * 0.5), (hero == hero_ ? mid_height : mid_height - card->height_));
				j++;
			}
			if (card->status_ == 2)
			{
				for (auto it = hero->hand_cards.begin(); it < hero->hand_cards.end(); it++)
				{
					if (*it == card)
					{
						hero->hand_cards.erase(it);
						card->status_ = 1;
						cards_.push_back(*it);
						//clear();
						//this->removeItem((*it)->graphicsProxyWidget())
					}					
				}
			}
		}
		
	}


}







