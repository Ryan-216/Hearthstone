#pragma once

#include <QtWidgets/QWidget>
#include "ui_Hearthstone.h"

class Hearthstone : public QWidget
{
    Q_OBJECT

public:
    Hearthstone(QWidget *parent = nullptr);
    ~Hearthstone();

private:
    Ui::HearthstoneClass ui;
};
