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
	bool common;          		//是否属于公共灯带，true：属于；false：不属于
	int x;						//横坐标
	int y;						//纵坐标	

	Precondition precondition;      //前置条件
	Led_Priority priority;          //优先级
	bool blink;               		//true:闪烁；flase:持续
	int cycle;						//闪烁周期（毫秒为单位）	
    std::string text_cn;  			//中文消息
    std::string text_en;  			//英文消息
	std::string sound;      		//声音文件路径
	std::string	icon;	        	//图标路径Precondition precondition;      //前置条件
	Led_Priority priority;          //优先级
	bool blink;               		//true:闪烁；flase:持续
	int cycle;						//闪烁周期（毫秒为单位）	
    std::string text_cn;  			//中文消息
    std::string text_en;  			//英文消息
	std::string sound;      		//声音文件路径
	std::string	icon;	        	//图标路径

public:
	Led();
	~Led();
};

#endif // LED_H
