# 分工



战场容器    5            

rhy

关于随从动态居中展示   关于坐标转化到具体哪个目标

纯氧

信号与槽

zyc

基础的功能函数（较简单）















rhy

主窗口  登陆界面  3  初始化比较复杂 需要连接信号 安排控件位置大小 移植

手牌容器    3.5        信号与槽比较多

派库  2



zyc

 card ability 4     鼠标事件比较复杂（需要设计3套鼠标事件）  设计一点信号与槽

法力水晶  2



纯氧    

fighter场上随从 3.5      一套鼠标拖动交互  一点点信号与槽 

hero object  2

help  minilabel  1



























## 主窗口   

初始化比较麻烦

需要把控件全部安排到位

需要进行信号与槽的连接



## cardclass 卡牌类

card手牌类  难点 鼠标交互 细节较多

英雄技能



## container容器类

手牌容器

主要是信号与槽比较多



战场容器 最难最复杂 

也许需要涉及随从动态居中 算法比较复杂

根据坐标计算落在哪一个目标上 算法上比较复杂

信号与槽比较多

法术效果的函数库 



## help

基本没什么 很简单



## cardlib牌库

涉及一点点信号和槽

初始话较麻烦



## object类

object   hero都比较简单 没什么内容

fighter

涉及鼠标操作 涉及一点点信号和槽



## 其余

法力水晶 

较简单 没什么功能













