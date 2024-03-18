#pragma once
#include"QLabel"
#include"string.h"
class minilabel;

//类简介
//卡牌类（手牌中每一张可以用鼠标交互的实体卡牌） 把随从牌和法术牌混合在一起 
//分为3种类型TYPE 随从 指向性法术 无指向性法术
//每种TYPE都有法力值消耗 卡牌名 卡牌介绍3个属性
// 随从牌有攻击力生命值
// 指向性法术和非指向性法术有自己的函数指针
// 每张卡只会有一种形态 与本牌形态无关的属性和方法无需关注
//初始化有3种方式 分别对应3种卡牌类型（见构造函数）

class card :
    public QLabel
{
    Q_OBJECT
public:
    enum CARDTYPE {
        MINION,//随从牌
        DIRSPELL,//指向性法术牌
        NONDIRSPELL//无指向性法术牌
    }card_type;
    
//----------------------------------------构造函数-------------------------------------------------------------
public:
    card(int _cost, void (*_dirfp)(QPoint target),std::string _name, QPoint p, QWidget* parent);//初始化指向性法术
    card( int _cost, std::string _name, void (*nondirfp)(), QPoint p, QWidget* parent);//初始化无指向法术
    card(int _cost, int _atk,int _hp,std::string _name, QPoint p, QWidget* parent);//初始化随从牌
    
//----------------------------------------构造函数-------------------------------------------------------------

    

//----------------------------------------数据成员-------------------------------------------------------------
protected:
    //随从法术均有属性
    std::string name;//卡牌名称
    std::string introduction;//卡牌效果的介绍
    int cost;//法力值消耗及其小标签
    minilabel* costlabel;//卡牌左上角显示法力值消耗的小标签
    //仅随从拥有属性
    int atk;//攻击力
    minilabel* atklabel;//卡牌左下角显示攻击力的小标签
    int hp;//生命值
    minilabel* hplabel;//卡牌右下角角显示生命的小标签
    CARDTYPE type;



public:
    //仅指向性法术拥有属性
    void (*dirfp)(QPoint target);//代表法术效果的指针 带有一个参数 代表法术指向的目标 由fightspace进行坐标转换
    //仅非指向性法术拥有属性
    void (*nondirfp)() ;//存放法术效果的函数指针 由于无指向性 故无参数
public:
    //常规尺寸
    static int w;
    static int h;
    //放大展示时尺寸
    int W;
    int H;
    QPoint m_pos;
    QPoint m_point;
    QPoint pos;
    
//----------------------------------------数据成员-------------------------------------------------------------



//----------------------------------------成员函数-------------------------------------------------------------
public:
    int getcost();//获取法力值消耗
    int getatk();//获取攻击力
    int gethp();//获取生命值
    QString getname();
    void init();//通用初始化函数 初始化大小 字体等常规项 在构造函数中调用 如果有多个构造函数 可以实现代码复用
//----------------------------------------成员函数-------------------------------------------------------------


    //----------------------------------------鼠标交互-------------------------------------------------------------
protected:
    //鼠标交互事件组 难点
    //不同类型的卡牌交互方式不同
    //实现效果：
    //对所有卡牌 鼠标放上去加边框指示 鼠标移开去除边框 即enter leave相同
    //其余逻辑不同 根据TYPE类型通过ifelse判断用哪一套逻辑
    //对随从牌 按住后可以拖动 在有效位置释放则出牌 
    //对非指向性法术 按住后可以拖动 在有效位置释放则出牌 （如悬停在战场上方为有效位置）
    //对非指向性法术 按住后不可拖动 会产生一个动态箭头 指向有效目标后释放鼠标则出牌 
    //出牌均通过信号与槽实现 如出牌有效 在mouseReleaseEvent中触发相应信号
    //只要能实现符合直觉的交互动作即可 可以自由发挥
    void enterEvent(QEnterEvent* event);
    void leaveEvent(QEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    //void paintEvent(QPaintEvent* event);

    //----------------------------------------鼠标交互-------------------------------------------------------------

    //---------------------------------------信号与槽-------------------------------------------------------------
signals:
    //向handcard发送 表示本牌将被打出到pos位置 第一个参数传this 第二个参数传打出位置 对于非指向性法术 传0，0作为标识
    void use(card* c, QPoint pos);


signals:
    void sendpos2space(QPoint p, bool start);//将全局鼠标坐标发给space

    //---------------------------------------信号与槽-------------------------------------------------------------

public:
    std::string id = "00000";//卡牌唯一标识，种类+效果类型+排序
    bool operator==(card* c);//重载 == 运算符
};













