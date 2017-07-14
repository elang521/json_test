//#pragma comment(lib, "json.lib")
#include <iostream>
#include <fstream>
#include <cassert>
#include "json/json.h"
#include "led/Led_Manager.h"
int main()
{
	Led_Manager *m_led_manager = Led_Manager::Get_Instance();
	return 0;
}