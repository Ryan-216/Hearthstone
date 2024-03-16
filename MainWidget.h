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
    int width_ = 1400, height_ = 950;//���ڿ��

    GameView game_view;
    LoginScene* login_scene = new LoginScene;//��¼����
    BattleScene* battle_scene = new BattleScene;//ս������
    MainWidget(QWidget* parent = nullptr);

    void start();
    void battle();

    ~MainWidget();

private:
    Ui::hearthstoneClass ui;
};

