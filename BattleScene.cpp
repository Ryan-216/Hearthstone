#include "BattleScene.h"
#include <algorithm>
#include <random>
#include <qdebug.h>
#include <QGraphicsSceneMouseEvent>


void BattleScene::battle_start()
{
	//从卡池里抽卡
	
	//


	
	
		
}

//QGraphicsSceneMouseEvent* mouse_event;

bool BattleScene::battle_loop()
{
	//if() 己方点按钮
	//我方计算法力值
	
	//敌方结束
	return true;
}
		


void BattleScene::mousePressEvent(QGraphicsSceneMouseEvent *mouse_event)
{
	
	if (mouse_event->button()==Qt::LeftButton)
	{
		
		const QList<QGraphicsItem*> mouse_items = this->items(mouse_event->scenePos());
		for (QGraphicsItem* item : mouse_items)
		{
			
		

		}

	}
	
}

void BattleScene::mouseMoveEvent(QGraphicsSceneMouseEvent* mouse_event)
{
	const QList<QGraphicsItem*> mouse_items = this->items(mouse_event->scenePos());
	for (QGraphicsItem* item : mouse_items) 
	{
		

		
	}
	
}









void BattleScene::end_turn()
{
	turn = false;
}

