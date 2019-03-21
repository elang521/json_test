#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include "../include/json_define.h"
using namespace std;

class Message
{
public:
    int id;
    std::string name;			    //名称
    Cancel_Type cancel;				//取消方式
    bool blink;					    //true:闪烁；flase:持续
    int cycle;					    //闪烁周期(单位毫秒)
    std::string text_cn;			//中文消息
    std::string text_en;			//英文消息
    std::string icon;				//图标路径
    std::string sound;				//声音路径
public:
    Message();
    ~Message();
};

#endif // MESSAGE_H
