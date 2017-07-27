#ifndef LED_H
#define LED_H
#include <iostream>
#include "../include/json_define.h"
using namespace std;

class Led
{
public:
	int id;
	int warning_id;				//告警id（为0时代表没有关联）
	int message_id;				//普通消息id（为0时代表没有关联）
	string name;				//名称
	Led_Priority priority;      //优先级
	Precondition precondition;	//前置条件
	std::string sound;      	//声音文件路径
	std::string	icon;	        //图标路径

public:
	Led();
	~Led();
};

#endif // LED_H
