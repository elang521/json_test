#include "Warning.h"

Warning::Warning()
{
    this->id=0;
    this->led_id=0;
    this->name=""; 
    this->icon=""; 
    this->sound=""; 
    this->movie="";
    this->cancel=Cancel_Type::general;
    this->priority=Warning_Priority::Warning_Priority1;
    this->blink=false;
    this->cycle=0;
    this->text_cn = "";
    this->text_en = "";
}

Warning::~Warning()
{

}
