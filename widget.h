#pragma once
#include <QWidget>
//自定义widget  添加了鼠标交互功能
class widget :
    public QWidget
{
public:
    widget(QWidget* parent);
protected:
    void enterEvent(QEnterEvent* event);//鼠标进入加边框
    void leaveEvent(QEvent* event);//鼠标移除删边框
};

