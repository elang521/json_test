#include "Message.h"

Message::Message()
{
	this->id = 0;
	this->name = "";			//名称
	this->cancel = Cancel_Type::general;						//取消方式
	this->blink=false;		//true:闪烁；flase:持续
	this->cycle=0;			//闪烁频率（单位毫秒）
	this->text_cn = "";		//显示消息
	this->text_en = "";		//显示消息
	this->icon = "";			//图标路径
	this->sound = "";
}

Message::~Message()
{

}
