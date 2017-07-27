#include "Warning.h"

Warning::Warning()
{
    this->id=0;
    this->led_id=0;
    this->name=""; 
    this->sound=""; 
    this->pop_up=false; 
    this->cancel=Cancel_Type::general;
    this->priority=Warning_Priority::Warning_Priority1;
    this->precondition=Precondition::always;

}

Warning::~Warning()
{

}
