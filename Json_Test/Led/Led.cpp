#include "Led.h"

Led::Led()
{
	this->id = 0;
	this->warning_id = 0;
	this->message_id = 0;
	this->name = "";
	this->precondition = Precondition::can;
	this->priority = Led_Priority::Priority1;
	this->sound = "";
}

Led::~Led()
{
}
