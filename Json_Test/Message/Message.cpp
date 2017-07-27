#include "Message.h"

Message::Message()
{
	this->id = 0;
	this->led_Id = 0;			//告警led的id
	this->name = "";			//名称
	this->cancel = Cancel_Type::general;						//取消方式
	this->precondition = Precondition::always;		//优先级
	this->priority = Message_Priority::Message_Priority1;		//优先级
	this->sound = "";
}

Message::~Message()
{

}
