#ifndef WARNINGMANAGER_H
#define WARNINGMANAGER_H
#include <stdio.h>
#include <QString>
#include <QJsonDocument>
#include <QDebug>
#include <QFile>
#include <QMap>
#include "Warning.h"

class WarningManager
{
public:
    static WarningManager *m_Manager;
public:

    bool IsExist(QString name);                                 //检查配置文件是否定义该LED灯
    bool GetWarningByName(QString name,Warning &m_Warning);     //获取某Led灯配置
    bool OnWarning(int m_WarningId);                            //告警触发
private:
    QVariantMap m_LedMap;                                       //配置文件map
    QMap<QString,Warning> m_WarningMap;                         //存放json定义的warning
protected:
    WarningManager();
    ~WarningManager();
private:
    void Init();
    bool ReadLedJson();                                         //读取ledjson配置文件
    bool AddToMap(const QVariantMap &ledMap);                   //将json信息存入内存

public:
    static  WarningManager * GetInstance();
};

#endif // WARNINGMANAGER_H
