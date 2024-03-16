#include "MainWidget.h"
#include <qdebug.h>

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->installEventFilter(this);
    this->show();
    this->setFixedSize(width_, height_);
    game_view.setFixedSize(width_ + 2, height_ + 2);
    game_view.setSceneRect(QRect(0, 0, width_, height_));
    game_view.setParent(this);
    game_view.show();
}

void MainWidget::start()
{
    show();
    game_view.setScene(login_scene);
    connect(login_scene->btn_login, &QPushButton::clicked, this, &MainWidget::battle);
    qDebug() << this->width_;
    qDebug() <<game_view.width();
    qDebug() <<login_scene->width_;
    qDebug() <<login_scene->bg_.width();
}

void MainWidget::battle()
{
    game_view.setScene(battle_scene);
    // battle_scene->battle();
}


MainWidget::~MainWidget()
{

}
