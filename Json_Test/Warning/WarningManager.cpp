#include "WarningManager.h"
#include <mutex>

WarningManager* WarningManager::m_Manager = NULL;\

WarningManager *WarningManager::GetInstance()
{
    std::mutex mutex;
    if (m_Manager == NULL)
    {
        mutex.lock();
        m_Manager = new WarningManager();
        mutex.unlock();
    }
    return m_Manager;
}


WarningManager::WarningManager()
{
    this->Init();
}

WarningManager::~WarningManager()
{

}

void WarningManager::Init()
{
	if (this->Read_Warning_Info())
	{

	}
	
}

bool WarningManager::Read_Warning_Info()
{
	std::ifstream ifs;
	ifs.open("conf/warning.json");
	assert(ifs.is_open());
	Json::Reader reader;
	Json::Value root;
	if (!reader.parse(ifs, root, true))
	{
		return false;
	}
	//int width = root["width"].asInt();
	//int height = root["width"].asInt();
	const Json::Value leds = root["leds"];
	unsigned int count = leds.size();
	if (count == 0)
	{
		return false;
	}
	for (unsigned int i = 0; i <count; ++i)
	{
		Warning m_info;
		m_info.id = leds[i]["id"].asInt();
		m_info.led_id = leds[i]["led_id"].asInt();
		m_info.name = leds[i]["name"].asString();
		m_info.priority = leds[i]["priority"].asInt();
		m_info.blink = leds[i]["blink"].asBool();
		m_info.cycle = leds[i]["cycle"].asInt();
		m_info.message = leds[i]["message"].asString();
		m_info.icon = leds[i]["icon"].asString();
		m_info.sound = leds[i]["sound"].asString();
		this->m_Warnings.push_back(m_info);
	}
	return true;
}

void WarningManager::OnAction(Led_Action_Type m_Type)
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
		//case��cl15off
	}
}

