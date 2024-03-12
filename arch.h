#pragma once

#include <QtWidgets/QWidget>
#include "ui_arch.h"

#include "GameView.h"
#include <qgraphicsscene.h>
#include "BaseScene.h"
#include "LoginScene.h"
#include "BattleScene.h"
#include "qlabel.h"
#include <qprogressbar.h>
#include <qdebug.h>

class arch : public QWidget//类名首字母未大写
{
    Q_OBJECT
public:
    
    arch(QWidget *parent = nullptr);
    void start();//游戏开始
    void battle();//战斗开始 
    ~arch();

private:
    Ui::archClass ui;
    int width_ = 900, height_ = 600;//窗口宽高

    QGraphicsView game_view;//游戏视图
    LoginScene* login_scene = new LoginScene;//登录场景
    BattleScene* battle_scene = new BattleScene;//战斗场景

    void end();//游戏结束
};
