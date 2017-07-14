#include "Led.h"

Led::Led()
{
	this->id=0;
	this->warningId=0;
	this->name="";	
	this->common=false; 
	this->x=0;
	this->y=0;	
	this->precondition = Precondition::can;
	this->priority=0;
	this->blink=false;
	this->cycle=0;
	this->message="";
	this->sound="";
	this->icon="";
}

Led::~Led()
{
}
