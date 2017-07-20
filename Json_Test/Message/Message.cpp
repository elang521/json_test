#include "Message.h"

Message::Message()
{
    this->id=0;
    this->led_Id=0;          //告警led的id
    this->name="";          //名称
    this->icon="";         //图标路径
    this->cancel=0;         //取消方式
    this->priority=0;		 //优先级
	this->sound = "";
    //this->blink=false;      //true:闪烁；flase:持续
    //this->cycle=0;		   //闪烁频率
	this->text_cn = "";   //显示消息
	this->text_en = "";   //显示消息
}

Message::~Message()
{

}
