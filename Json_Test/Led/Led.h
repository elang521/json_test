#ifndef LED_H
#define LED_H
#include <iostream>
#include "../include/json_define.h"
using namespace std;

class Led
{
public:
	int id;
	int warningId;			//告警led的id
	string name;				//名称
	bool common;          //是否属于公共灯带
	int x;							//横坐标
	int y;							//纵坐标

	Precondition precondition;       //前置条件
	int priority;               //优先级
	bool blink;               //true:闪烁；flase:持续
	int cycle;					//闪烁周期
	std::string message;  //显示消息
	std::string sound;      //声音文件路径
	std::string	icon;	        //图标路径

public:
	Led();
	~Led();
};

#endif // LED_H
