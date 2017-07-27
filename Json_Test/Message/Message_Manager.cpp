#include "Message_Manager.h"
#include <mutex>

Message_Manager *Message_Manager::m_Manager = NULL;

Message_Manager *Message_Manager::Get_Instance()
{
    std::mutex mutex;
    if (m_Manager == NULL)
    {
        mutex.lock();
        m_Manager = new Message_Manager();
        mutex.unlock();
    }
    return m_Manager;
}

Message_Manager::Message_Manager()
{

    this->Init();
}

Message_Manager::~Message_Manager()
{
}

void Message_Manager::Init()
{
    this->m_Messages.clear();
    if (this->Read_Message_Info())
    {
    }
}

bool Message_Manager::Read_Message_Info()
{
    std::ifstream ifs;
    ifs.open("conf/message.json");
    assert(ifs.is_open());
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(ifs, root, true))
    {
        return false;
    }
    this->x = root["x"].asInt();
    this->y = root["y"].asInt();
    this->width = root["width"].asInt();
    this->height = root["height"].asInt();
    const Json::Value messages = root["Messages"];
    int count = messages.size();
    for (unsigned int i = 0; i < messages.size(); ++i)
    {
        Message m_info;
        m_info.id = messages[i]["id"].asInt();
        m_info.name = messages[i]["name"].asString();
        m_info.cancel = (Cancel_Type)messages[i]["cancel"].asInt();
        m_info.blink = messages[i]["blink"].asBool();
        m_info.cycle = messages[i]["cycle"].asInt();
        m_info.text_cn = messages[i]["text_cn"].asString();
        m_info.text_en = messages[i]["text_en"].asString();
        m_info.icon = messages[i]["icon"].asString();
        m_info.sound = messages[i]["sound"].asString();
        m_Messages.push_back(m_info);
    }
    return false;
}

void Message_Manager::OnAction(int m_Id, Message_Action_Type m_Type)
{
    //判断来的是什么信号
    switch (m_Type)
    {
        //case:on
        //判断是否已经在打开队列
        //判断前置条件，是否应该打开
        //发送打开组包，并将其加入已经打开队列

        //case:off
        //判断是否在打开队列，不在直接忽略
        //发送关闭组包，并将其移出打开队列

        //case:can on
        //case:can off

        //case:cl15on
        //case:cl15off
    }
}
