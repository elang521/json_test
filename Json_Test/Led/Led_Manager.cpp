#include "Led_Manager.h"

Led_Manager* Led_Manager::m_Manager = NULL;
Led_Manager *Led_Manager::Get_Instance()
{
    std::mutex mutex;
    if (m_Manager == NULL)
    {
        mutex.lock();
        m_Manager = new Led_Manager();
        mutex.unlock();
    }
    return m_Manager;
}

Led_Manager::Led_Manager()
{
	this->Init();
}

Led_Manager::~Led_Manager()
{

}


void Led_Manager::Init()
{
	this->m_leds.clear();
	this->m_open_leds.clear();
	if (this->Read_Led_Info())
	{

	}
}

bool Led_Manager::Read_Led_Info()
{
	std::ifstream ifs;
	ifs.open("conf/led.json");
	assert(ifs.is_open());
	Json::Reader reader;
	Json::Value root;
	if (!reader.parse(ifs, root, true))
	{
		return -1;	
	}
	int width = root["width"].asInt();
	int height = root["width"].asInt();
	const Json::Value leds = root["leds"];
	int count = leds.size();
	for (unsigned int i = 0; i < leds.size(); ++i)
	{
		Led m_info;
		m_info.id = leds[i]["id"].asInt();
		m_info.warningId = leds[i]["warning_id"].asInt();
		m_info.name = leds[i]["name"].asString();
		m_info.precondition = (Precondition)leds[i]["precondition"].asInt();
		m_info.common = leds[i]["common"].asBool();
		m_info.x = leds[i]["x"].asInt();
		m_info.y = leds[i]["y"].asInt();
		m_info.priority = leds[i]["priority"].asInt();
		m_info.blink = leds[i]["blink"].asInt();
		m_info.cycle = leds[i]["cycle"].asInt();
		m_info.message = leds[i]["message"].asString();
		m_info.icon = leds[i]["icon"].asString();
		m_info.sound = leds[i]["sound"].asString();
		m_leds.push_back(m_info);
	}
	return false;
}

void Led_Manager::OnSignal()
{
	//判断来的是什么信号

	//如果是开灯信号
	//根据led的id，将需要打开的led信息加入m_open_leds
}
