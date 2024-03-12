#pragma once

#include <QtWidgets/QWidget>
#include "ui_arch.h"

#include "GameView.h"
#include <qgraphicsscene.h>
#include "BaseScene.h"
#include "LoginScene.h"
#include "BattleScene.h"
#include<qprogressbar.h>

class arch : public QWidget//��������ĸδ��д
{
    //Q_OBJECT
public:
    

    arch(QWidget *parent = nullptr);
    void start();//��Ϸ��ʼ
    void battle();//ս��

public slots:
    void enter_battle_scene();

    ~arch();

private:
    Ui::archClass ui;
    int width_ = 900, height_ = 600;//���ڿ��
    QGraphicsView game_view;//��Ϸ��ͼ

    //QGraphicsPixmapItem *test = new QGraphicsPixmapItem;
    //MinionCard *test = new MinionCard;

    LoginScene login_scene;//��¼����
    BattleScene* battle_scene = new BattleScene;//ս������

    QPushButton* btn_login = new QPushButton;
    QPushButton* btn_end_of_turn = new QPushButton;
    QProgressBar* grid_mana_bar = new QProgressBar();
    // void mouseMoveEvent(QMouseEvent* event);


    void end();//��Ϸ����
};
