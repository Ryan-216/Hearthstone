#include "BattleScene.h"
#include <algorithm>
#include <random>
#include <qdebug.h>
#include <QGraphicsSceneMouseEvent>


void BattleScene::battle_start()
{
	//�ӿ�����鿨
	
	//


	
	
		
}

//QGraphicsSceneMouseEvent* mouse_event;

bool BattleScene::battle_loop()
{
	//if() �����㰴ť
	//�ҷ����㷨��ֵ
	
	//�з�����
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

