#ifndef WARNING_H
#define WARNING_H
#include <iostream>
#include "../include/json_define.h"


class Warning
{
public:
	int id;
	int led_id;							//对应led的id
	std::string name;					//名称
	//int x;							//横坐标
	//int y;							//纵坐标
	//int width;						//宽度
	//int height;						//高度
	//std::string resolution;			//分辨率
	//int resourceX;					//资源X坐标
	//int resourceY;					//资源Y坐标

	Cancel_Type cancel;					//取消方式
	Warning_Priority priority;			//优先级
	bool pop_up;						//是否突出显示
	bool blink;							//true:闪烁；flase:持续
	int cycle;							//闪烁周期
    std::string text_cn;				//中文消息
    std::string text_en;				//英文消息
	std::string icon;					//图标路径
	std::string sound;					//声音文件路径
	std::string movie;					//动画资源路径或者Id，动画资源有自己独立的配置文件
public:
	Warning();
	~Warning();
};

#endif // WARNING_H
