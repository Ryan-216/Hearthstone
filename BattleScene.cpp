#include "BattleScene.h"
#include <QGraphicsProxyWidget>

void BattleScene::battle()
{
	//初始抽牌
	draw_cards(hero_, 5);
	draw_cards(enemy_, 5);	
	paint_text(hero_);
	paint_text(enemy_);
	paint_notice();

	timer_1 = new QTimer();
	timer_1->start(20);	
	connect(timer_1, &QTimer::timeout, [this]() {
		this->fake_mouse();
		//any_drag = this->mouseGrabberItem() == nullptr;
		//qDebug() << any_drag;
		if (mouse_ == -1)
		{
			manage_attack();
			paint_all();		
		}
		});
	
	timer_2 = new QTimer();
	timer_2->start(5000);
	connect(timer_2, &QTimer::timeout, [this]() {notice_info = (turn ? "Please move your minions to attack the enemy" : "The enemy is moving his minions to attack you"); paint_notice(); });

	connect(this->btn_end_of_turn, &QPushButton::clicked,this, &BattleScene::turn_change);

	
	
}

void BattleScene::manage_attack()
{
	BaseCard* attacker = new BaseCard;
	
	if (turn)
	{		

		for (auto it = hero_->hand_cards.begin(); it < hero_->hand_cards.end(); it++)
		{
			if ((*it)->status_ == 1 && (*it)->isAttacker) { attacker = (*it); break; }
		}		
		bool count_battle = false;
		for (auto it = enemy_->hand_cards.begin(); it < enemy_->hand_cards.end(); it++)
		{
			if ((*it)->status_ == 1)
			{
				count_battle = true;
				if (mouse_pos.x() - (*it)->pos().x() <= (*it)->widght_ && mouse_pos.x() - (*it)->pos().x() >= 0 &&
					mouse_pos.y() - (*it)->pos().y() <= (*it)->height_ && mouse_pos.y() - (*it)->pos().y() >= 0)
				{
					// qDebug() << "attack";
					attacker->Attack(*it);
					hero_->remain_spell_ -= attacker->cost_;
					paint_text(hero_);
					qDebug() << "attacker";
					qDebug() << attacker->status_;
					attacker->isAttacker = false;
					attacker->Death();
					qDebug() << attacker->status_;
					
					(*it)->Death();
					paint_cards(enemy_);
					paint_cards(hero_);
				}								
			};
		}	
		if (mouse_pos.x() - enemy_->pos().x() <= enemy_->width_ && mouse_pos.x() - enemy_->pos().x() >= 0 &&
			mouse_pos.y() - enemy_->pos().y() <= enemy_->height_ && mouse_pos.y() - enemy_->pos().y() >= 0)
		{
			if (!count_battle)
			{
				attacker->Attack(enemy_);
				hero_->remain_spell_ -= attacker->cost_;
				paint_text(hero_);
				qDebug() << "attack enemy";
				qDebug() << enemy_->blood_;
				if (enemy_->blood_ <= 0)
				{
					end(true);
				}
				else
				{
					notice_info = QString("Excellent! the enemy lost %1 blood, he has %2 blood left").arg(attacker->attack_).arg(enemy_->blood_);
					paint_notice();
				}
			}
			else
			{
				notice_info = "You must attack the mimions on the battlefield first";
				paint_notice();
			}
			
		}
	}
	else
	{
		for (auto it = enemy_->hand_cards.begin(); it < enemy_->hand_cards.end(); it++)
		{
			if ((*it)->status_ == 1 && (*it)->isAttacker) { attacker = (*it); break; }
		}
		if (mouse_pos.x() - hero_->pos().x() <= hero_->width_ && mouse_pos.x() - hero_->pos().x() >= 0 &&
			mouse_pos.y() - hero_->pos().y() <= hero_->height_ && mouse_pos.y() - hero_->pos().y() >= 0)
		{
			attacker->Attack(hero_);
			enemy_->remain_spell_ -= attacker->cost_;
			paint_text(enemy_);
			qDebug() << "attack hero";
			if (hero_->blood_ <= 0)end(false);
		}
		for (auto it = hero_->hand_cards.begin(); it < hero_->hand_cards.end(); it++)
		{
			if ((*it)->status_ == 1)
			{
				if (mouse_pos.x() - (*it)->pos().x() <= (*it)->widght_ && mouse_pos.x() - (*it)->pos().x() >= 0 &&
					mouse_pos.y() - (*it)->pos().y() <= (*it)->height_ && mouse_pos.y() - (*it)->pos().y() >= 0)
				{
					attacker->Attack(*it);
					enemy_->remain_spell_ -= attacker->cost_;
					paint_text(enemy_);
					attacker->isAttacker = false;
					attacker->Death();
					(*it)->Death();
					paint_cards(enemy_);
					paint_cards(hero_);
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

void BattleScene::end(bool e)
{
	qDebug() << (e ? "win" : "lose");	
	QString ending_text = e ? "win" : "lose";
	this->addWidget(&ending);
	ending.setAlignment(Qt::AlignCenter);
	ending.setFont(QFont("timesnewroman", 50, 20, 0));
	ending.setText(e ? "win" : "lose");
	ending.setFixedSize(400, 500);
	ending.move((width_ - ending.width()) * 0.5, (height_ - ending.height()) * 0.5);

	back->setText("Back");
	back->resize(100, 40);
	back->setFont(QFont("timesnewroman", 10, 4, 0));
	back->move((width_ - back->width()) / 2, (height_ - back->height()) / 2 + 200);
	this->addWidget(back);
}

int i = 0;

void BattleScene::turn_change()
{
	//true 我方 false 敌方

	turn = !turn;
	i++;
	if (i == 2)
	{
		num_of_turn_++;
		i = 0;
	}
	qDebug() << num_of_turn_;
	for (auto it = hero_->hand_cards.begin(); it < hero_->hand_cards.end(); it++)
	{
		(*it)->allow_click_ = turn;//设置为是否移动
	}
	for (auto it = enemy_->hand_cards.begin(); it < enemy_->hand_cards.end(); it++)
	{
		(*it)->allow_click_ = !turn;//设置为是否移动
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
		(*it)->allow_click_ = (num > 1 ? (hero == hero_) : true);
		this->addWidget((*it));
		//connect((*it), &BaseCard::status_change, this, &BattleScene::paint_all);
		//connect((*it), SIGNAL(status_change()), this, SLOT(paint_all()));
		cards_.erase(it);
		num--;
	}
	paint_cards(hero);
}

void BattleScene::paint_text(Hero* hero)
{
	int mid_width = width_ / 2;
	QString text_hero = QString("HP: %1, MSP: %2, RSP: %3, CARD0: %4, CARD1: %5").arg(hero_->blood_).arg(hero_->max_spell).arg(hero_->remain_spell_).arg(hero_->cards_num[0]).arg(hero_->cards_num[1]);
	QString text_enemy = QString("HP: %1, MSP: %2, RSP: %3,CARD0: %4,, CARD1: %5").arg(enemy_->blood_).arg(enemy_->max_spell).arg(enemy_->remain_spell_).arg(enemy_->cards_num[0]).arg(enemy_->cards_num[1]);
	hero_status->setText(text_hero);
	hero_status->setAlignment(Qt::AlignCenter);
	hero_status->resize(300,30);
	hero_status->move(mid_width - hero_status->width() * 0.5, 600);

	enemy_status->setText(text_enemy);
	enemy_status->setAlignment(Qt::AlignCenter);
	enemy_status->resize(300, 30);
	enemy_status->move(mid_width - enemy_status->width() * 0.5, 170);
}

void BattleScene::paint_notice()
{
	int mid_width = width_ / 2;
	notice->setAlignment(Qt::AlignCenter);
	notice->setText(notice_info);
	notice->resize(680, 40);
	notice->move(mid_width - notice->width() * 0.5, 380);
}

void  BattleScene::paint_all()
{
	paint_cards(hero_);
	paint_cards(enemy_);
	paint_text(hero_);
	paint_text(enemy_);
}

void BattleScene::paint_cards(Hero* hero)
{
	for (BaseCard* card : hero->hand_cards)
	{
		if (card->cost_ > hero->remain_spell_)
		{
			card->allow_click_ = false;
		}
		else
		{
			card->allow_click_ = true;
		}
	}
	//0手牌，1战斗，2死亡
	for (int i = 0; i < 3; i++) { hero->cards_num[i] = 0; }
	int mid_width = width_ / 2;
	int mid_height = height_ / 2;
	int i = 0, j = 0;
	hero->move(mid_width - hero->width_ * 0.5, (hero == hero_) ? 650 : 100);
	for (BaseCard* card : hero->hand_cards) hero->cards_num[card->status_]++;
	for (BaseCard* card : hero->hand_cards)
	{		
		if (!card->isDragging)
		{			
			if (card->status_ == 0)
			{
				card->move(mid_width + (card->widght_ + 10) * (i - hero->cards_num[0] * 0.5), (hero == hero_ ? height_ - card->height_ : 0));
				i++;
			}
			if (card->status_ == 1)
			{
				card->move(mid_width + (card->widght_ + 10) * (j - hero->cards_num[1] * 0.5), (hero == hero_ ? mid_height + 40 : mid_height - card->height_ - 40));
				j++;
			}
			
			if (card->status_ == 2)
			{
				for (auto it = hero->hand_cards.begin(); it < hero->hand_cards.end(); it++)
				{
					if (*it == card)
					{
						this->removeItem((*it)->graphicsProxyWidget());
						hero->hand_cards.erase(it);
						// card->status_ = 1;
						// cards_.push_back(*it);									
						break;
					}					
				}
			}
		}
		
	}


}







