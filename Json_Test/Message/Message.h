#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include "../include/json_define.h"
using namespace std;

class Message
{
public:
    int id;
    int led_Id;						//告警led的id
    std::string name;			    //名称
    Cancel_Type cancel;				//取消方式
 	Precondition precondition;	    //前置条件   
    Message_Priority priority;		//优先级
    std::string sound;				//声音路径
public:
    Message();
    ~Message();
};

#endif // MESSAGE_H
