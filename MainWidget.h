#pragma once
#include <qwidget.h>
#include "LoginScene.h"
#include "BattleScene.h"
#include "GameView.h"
#include "ui_hearthstone.h"

class MainWidget :
    public QWidget
{
    Q_OBJECT
public:
    int width_ = 1400, height_ = 950;//窗口宽高

    GameView game_view;
    LoginScene* login_scene = new LoginScene;//登录场景
    BattleScene* battle_scene = new BattleScene;//战斗场景
    MainWidget(QWidget* parent = nullptr);

    void start();
    void battle();

    ~MainWidget();

private:
    Ui::hearthstoneClass ui;
};

