#include "Led.h"

Led::Led()
{
	this->id = 0;
	this->warning_id = 0;
	this->message_id = 0;
	this->name = "";
	this->common = false;
	this->x = 0;
	this->y = 0;
	this->precondition = Precondition::can;
	this->priority = Led_Priority::Priority1;
	this->blink = false;
	this->cycle = 0;
	this->text_cn = "";
	this->text_en = "";
	this->sound = "";
	this->icon = "";
}

Led::~Led()
{
}
