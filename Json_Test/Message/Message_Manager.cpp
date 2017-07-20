#include "Message_Manager.h"
#include <mutex>

Message_Manager* Message_Manager::m_Manager = NULL;\

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
    int width = root["width"].asInt();
    int height = root["width"].asInt();
    const Json::Value leds = root["Messages"];
    int count = leds.size();
    for (unsigned int i = 0; i < leds.size(); ++i)
    {
        Message m_info;
        m_info.id = leds[i]["id"].asInt();
        m_info.led_Id = leds[i]["led_Id"].asInt();
        m_info.name = leds[i]["name"].asString();
        m_info.priority = leds[i]["priority"].asInt();
        m_info.text_cn = leds[i]["text_cn"].asString();
        m_info.text_en = leds[i]["text_en"].asString();
        m_info.icon = leds[i]["icon"].asString();
        m_info.sound = leds[i]["sound"].asString();
        m_Messages.push_back(m_info);
    }
    return false;
}

void Message_Manager::OnAction(Message_Action_Type m_Type)
{
    //�ж�������ʲô�ź�
    switch (m_Type)
    {
        //case:on
        //�ж��Ƿ��Ѿ��ڴ򿪶���
        //�ж�ǰ���������Ƿ�Ӧ�ô�
        //���ʹ����������������Ѿ��򿪶���

        //case:off
        //�ж��Ƿ��ڴ򿪶��У�����ֱ�Ӻ���
        //���͹ر�������������Ƴ��򿪶���

        //case:can on
        //case:can off

        //case:cl15on
        //case:cl15off
    }
}

