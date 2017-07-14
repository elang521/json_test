#include "Warning.h"

Warning::Warning()
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
    this->Sound="";         //声音文件路径
    this->Movie="";         //动画资源路径或者Id，动画资源有自己独立的配置文件
    this->Cancel=0;         //取消方式
    this->ResourceX=0;      //资源X坐标
    this->ResourceY=0;      //资源Y坐标
    this->Priority=0;       //优先级
    this->Blink=false;      //true:闪烁；flase:持续
    this->Frequency=0;      //闪烁频率
    this->State=false;      //状态
    this->Message="";       //显示消息
    this->Common=false;     //是否属于公共区域 true:属于 false:不属于
}

Warning::~Warning()
{

}

void Warning::SetId(int id)
{
    this->Id=id;
}

int Warning::GetId()
{
    return this->Id;
}

void Warning::SetLedId(int ledId)
{
    this->LedId=ledId;
}

int Warning::GetLedId()
{
    return this->LedId;
}

void Warning::SetName(QString name)
{
    this->Name=name;
}

QString Warning::GetName()
{
    return this->Name;
}

void Warning::SetX(int x)
{
    this->X=x;
}

int Warning::GetX()
{
    return this->X;
}

void Warning::SetY(int y)
{
    this->Y=y;
}

int Warning::GetY()
{
    return this->Y;
}

void Warning::SetWidth(int width)
{
    this->Width=width;
}

int Warning::GetWidth()
{
    return this->Width;
}

void Warning::SetHeight(int height)
{
    this->Height=height;
}

int Warning::GetHeight()
{
    return this->Height;
}

void Warning::SetColor(int color)
{
    this->Color=color;
}

QString Warning::GetColor()
{
    return this->Color;
}

void Warning::SetImage(QString image)
{
    this->Image=image;
}

QString Warning::GetImage()
{
    return this->Image;
}

void Warning::SetResolution(QString resolution)
{
    this->Resolution=resolution;
}

QString Warning::GetResolution()
{
    return this->Resolution;
}

void Warning::SetSound(QString sound)
{
    this->Sound=sound;
}

QString Warning::GetSound()
{
    return this->Sound;

}

void Warning::SetMovie(QString movie)
{
    this->Movie=movie;
}

QString Warning::GetMovie()
{
    return this->Movie;
}

void Warning::SetCancel(int cancel)
{
    this->Cancel=cancel;
}

int Warning::GetCancel()
{
    return this->Cancel;
}

void Warning::SetResourceX(int resourceX)
{
    this->ResourceX=resourceX;
}

int Warning::GetResourceX()
{
    return this->ResourceX;
}

void Warning::SetResourceY(int resourceY)
{
    this->ResourceY=resourceY;
}

int Warning::GetResourceY()
{
    return this->ResourceY;
}

void Warning::SetPriority(int priority)
{
    this->Priority=priority;
}

int Warning::GetPriority()
{
    return this->Priority;
}

void Warning::SetBlink(bool blink)
{
    this->Blink=blink;
}

bool Warning::GetBlink()
{
    return this->Blink;
}

void Warning::SetFrequency(int frequency)
{
    this->Frequency=frequency;
}

int Warning::GetFrequencry()
{
    return this->Frequency;
}

void Warning::SetState(bool state)
{
    this->State=state;
}

bool Warning::GetState()
{
    return this->State;
}

void Warning::SetMessage(QString message)
{
    this->Message=message;
}

QString Warning::GetMessage()
{
    return this->Message;
}

void Warning::SetCommon(bool common)
{
    this->Common=common;z
}

bool Warning::GetCommon()
{
    return this->Common;
}
