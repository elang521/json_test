#ifndef Message_Manager_H
#define Message_Manager_H
#include <mutex>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <list>
#include "Message.h"
#include "../json/json.h"

class Message_Manager
{
public:
    static Message_Manager *m_Manager;
public:
    static  Message_Manager * Get_Instance();

protected:
    Message_Manager();
    ~Message_Manager();
private:
    std::vector<Message> m_Messages;					            //存在的led等信息列表
private:
    void Init();
    bool Read_Message_Info();											//读取warningjson配置文件
    void OnAction(Message_Action_Type m_Type);				//根据信号的不同，执行不同的操作

};

#endif // Message_Manager_H
