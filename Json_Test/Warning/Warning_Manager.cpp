#include "Warning_Manager.h"
#include <mutex>

Warning_Manager *Warning_Manager::m_Manager = NULL;

Warning_Manager *Warning_Manager::GetInstance()
{
	std::mutex mutex;
	if (m_Manager == NULL)
	{
		mutex.lock();
		m_Manager = new Warning_Manager();
		mutex.unlock();
	}
	return m_Manager;
}

Warning_Manager::Warning_Manager()
{
	this->Init();
}

Warning_Manager::~Warning_Manager()
{
}

void Warning_Manager::Init()
{
	if (this->Read_Warning_Info())
	{
	}
}

bool Warning_Manager::Read_Warning_Info()
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
	const Json::Value warnings = root["warnings"];
	unsigned int count = warnings.size();
	if (count == 0)
	{
		return false;
	}
	for (unsigned int i = 0; i < count; ++i)
	{
		Warning m_info;
		m_info.id = warnings[i]["id"].asInt();
		m_info.name = warnings[i]["name"].asString();
		m_info.cancel = (Cancel_Type)warnings[i]["cancel"].asInt();
		m_info.pop_up = warnings[i]["pop_up"].asBool();
		m_info.blink = warnings[i]["blink"].asBool();
		m_info.cycle = warnings[i]["cycle"].asInt();
		m_info.text_cn = warnings[i]["text_cn"].asString();
		m_info.text_en = warnings[i]["text_en"].asString();
		m_info.icon = warnings[i]["icon"].asString();
		m_info.sound = warnings[i]["sound"].asString();
		m_info.movie = warnings[i]["movie"].asString();
		this->m_Warnings.push_back(m_info);
	}
	return true;
}

void Warning_Manager::OnAction(int m_Id, Warning_Action_Type m_Type)
{
	//判断来的是什么信号?
	switch (m_Type)
	{
		//case:on
		//判断是否已经在打开队列
		//判断前置条件，是否应该打开
		//发送打开组包，并将其加入已经打开队列

		//case:off
		//判断是否在打开队列，不在直接忽略？
		//发送关闭组包，并将其移出打开队列

		//case:can on
		//case:can off

		//case:cl15on
		//case:cl15off
	}
}
