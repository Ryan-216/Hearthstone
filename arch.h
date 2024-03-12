#pragma once

#include <QtWidgets/QWidget>
#include "ui_arch.h"

#include "GameView.h"
#include <qgraphicsscene.h>
#include "BaseScene.h"
#include "LoginScene.h"
#include "BattleScene.h"
#include<qprogressbar.h>

class arch : public QWidget//类名首字母未大写
{
    //Q_OBJECT
public:
    

    arch(QWidget *parent = nullptr);
    void start();//游戏开始
    void battle();//战斗

public slots:
    void enter_battle_scene();

    ~arch();

private:
    Ui::archClass ui;
    int width_ = 900, height_ = 600;//窗口宽高
    QGraphicsView game_view;//游戏视图

    //QGraphicsPixmapItem *test = new QGraphicsPixmapItem;
    //MinionCard *test = new MinionCard;

    LoginScene login_scene;//登录场景
    BattleScene* battle_scene = new BattleScene;//战斗场景

    QPushButton* btn_login = new QPushButton;
    QPushButton* btn_end_of_turn = new QPushButton;
    QProgressBar* grid_mana_bar = new QProgressBar();
    // void mouseMoveEvent(QMouseEvent* event);


    void end();//游戏结束
};
