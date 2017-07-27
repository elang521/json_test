#ifndef Warning_Manager_H
#define Warning_Manager_H
#include <iostream>
#include <fstream>
#include <cassert>
#include "Warning.h"
#include "../json/json.h"

class Warning_Manager
{
  public:
    static Warning_Manager *m_Manager;

  private:
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    std::vector<Warning> m_Warnings;

  protected:
    Warning_Manager();
    ~Warning_Manager();

  private:
    void Init();
    bool Read_Warning_Info();                            //读取warningjson配置文件
    void OnAction(int m_Id, Warning_Action_Type m_Type); //根据信号的不同，执行不同的操作
  public:
    static Warning_Manager *GetInstance();
};

#endif // Warning_Manager_H
