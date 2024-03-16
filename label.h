#pragma once
#include<QLabel>
//自定义QLabel 添加了鼠标交互功能
class label :
    public QLabel
{
public:
    label() {};
    label(QWidget* parent);
protected:
    void enterEvent(QEnterEvent* event);//鼠标进入加边框
    void leaveEvent(QEvent* event);//鼠标移除删边框
};

