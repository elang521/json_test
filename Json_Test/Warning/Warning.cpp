#include "Warning.h"

Warning::Warning()
{
    this->id=0;
    this->led_id=0;
    this->name=""; 
    //this->x=0;
    //this->y=0; 
    //this->width=0; 
    //this->height=0;
    this->icon=""; 
    //this->resolution=""; 
    this->sound=""; 
    this->movie="";
    this->cancel=Cancel_Type::general;
    //this->resourceX=0;
    //this->resourceY=0; 
    this->priority=0;
    this->blink=false;
    this->cycle=0;
    this->text_cn = "";
    this->text_en = "";
}

Warning::~Warning()
{

}
