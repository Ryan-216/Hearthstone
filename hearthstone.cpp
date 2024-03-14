#include "hearthstone.h"

hearthstone::hearthstone(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    resize(1400, 950);
}

hearthstone::~hearthstone()
{}
