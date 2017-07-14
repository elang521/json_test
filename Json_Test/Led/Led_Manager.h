#ifndef Led_Manager_H
#define Led_Manager_H

#include <iostream>
#include "Led.h"
#include <mutex>
#include <fstream>
#include <cassert>
#include<list>
#include<vector>
#include "../json/json.h"
//#include "../include/json_define.h"

class Led_Manager
{
public:
    static Led_Manager *m_Manager;
public:
    static  Led_Manager * Get_Instance();

private:
	std::vector<Led> m_leds;					//存在的led等信息列表
	std::list<Led> m_open_leds;				//存放已经打开的led灯
protected:
    Led_Manager();
    ~Led_Manager();
private:
    void Init();
    bool Read_Led_Info();                         //读取ledjson配置文件
	void OnSignal();
		
};

#endif // Led_Manager_H
