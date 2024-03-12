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

class arch : public QWidget//��������ĸδ��д
{
    Q_OBJECT
public:
    
    arch(QWidget *parent = nullptr);
    void start();//��Ϸ��ʼ
    void battle();//ս����ʼ 
    ~arch();

private:
    Ui::archClass ui;
    int width_ = 900, height_ = 600;//���ڿ��

    QGraphicsView game_view;//��Ϸ��ͼ
    LoginScene* login_scene = new LoginScene;//��¼����
    BattleScene* battle_scene = new BattleScene;//ս������

    void end();//��Ϸ����
};
