#include "Message.h"

Message::Message()
{
    this->Id=0;
    this->LedId=0;          //告警led的id
    this->Name="";          //名称
    this->X=0;              //横坐标
    this->Y=0;              //纵坐标
    this->Width=0;          //宽度
    this->Height=0;         //高度
    this->Color="";         //图标颜色
    this->Image="";         //图标路径
    this->Resolution="";    //分辨率
    this->Cancel=0;         //取消方式
    this->Priority=0;       //优先级
    this->Blink=false;      //true:闪烁；flase:持续
    this->Frequency=0;      //闪烁频率
    this->State=false;      //状态
    this->mMessage="";       //显示消息
}

Message::~Message()
{

}

void Message::SetId(int id)
{
    this->Id=id;
}

int Message::GetId()
{
    return this->Id;
}

void Message::SetLedId(int ledId)
{
    this->LedId=ledId;
}

int Message::GetLedId()
{
    return this->LedId;
}

void Message::SetName(QString name)
{
    this->Name=name;
}

QString Message::GetName()
{
    return this->Name;
}

void Message::SetX(int x)
{
    this->X=x;
}

int Message::GetX()
{
    return this->X;
}

void Message::SetY(int y)
{
    this->Y=y;
}

int Message::GetY()
{
    return this->Y;
}

void Message::SetWidth(int width)
{
    this->Width=width;
}

int Message::GetWidth()
{
    return this->Width;
}

void Message::SetHeight(int height)
{
    this->Height=height;
}

int Message::GetHeight()
{
    return this->Height;
}

void Message::SetColor(int color)
{
    this->Color=color;
}

QString Message::GetColor()
{
    return this->Color;
}

void Message::SetImage(QString image)
{
    this->Image=image;
}

QString Message::GetImage()
{
    return this->Image;
}

void Message::SetResolution(QString resolution)
{
    this->Resolution=resolution;
}

QString Message::GetResolution()
{
    return this->Resolution;
}

void Message::SetCancel(int cancel)
{
    this->Cancel=cancel;
}



void Message::SetPriority(int priority)
{
    this->Priority=priority;
}

int Message::GetPriority()
{
    return this->Priority;
}

void Message::SetBlink(bool blink)
{
    this->Blink=blink;
}

bool Message::GetBlink()
{
    return this->Blink;
}

void Message::SetFrequency(int frequency)
{
    this->Frequency=frequency;
}

int Message::GetFrequencry()
{
    return this->Frequency;
}

void Message::SetState(bool state)
{
    this->State=state;
}

bool Message::GetState()
{
    return this->State;
}

void Message::SetMessage(QString message)
{
    this->mMessage=message;
}

QString Message::GetMessage()
{
    return this->mMessage;
}
