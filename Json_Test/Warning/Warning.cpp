#include "Warning.h"

Warning::Warning()
{
    this->id=0;    
    this->name=""; 
    this->icon=""; 
    this->pop_up=false;
    this->sound=""; 
    this->movie="";
    this->cancel=Cancel_Type::general;
    this->blink=false;
    this->cycle=0;
    this->text_cn = "";
    this->text_en = "";
}

Warning::~Warning()
{

}
