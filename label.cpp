#include "label.h"

label::label(QWidget* parent):QLabel(parent)
{
}

void label::enterEvent(QEnterEvent* event)
{
	setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(255, 0, 0);");
}

void label::leaveEvent(QEvent* event)
{
	setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 0, 0);");
}
