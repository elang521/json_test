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
	Cancel_Type cancel;					//取消方式
	Warning_Priority priority;			//优先级
	Precondition precondition;	    	//前置条件   
	bool pop_up;						//是否突出显示
	std::string sound;					//声音文件路径
public:
	Warning();
	~Warning();
};

#endif // WARNING_H
