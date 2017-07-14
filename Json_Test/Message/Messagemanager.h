#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H
#include <QString>
#include <mutex>
#include <stdio.h>
#include <QString>
#include <QJsonDocument>
#include <QDebug>
#include <QFile>
#include <QMap>
#include "Message.h"

class MessageManager
{
public:
    static MessageManager *m_Manager;
public:
    static  MessageManager * GetInstance();
public:

    bool IsExist(QString name);                                 //检查配置文件是否定义该LED灯
    bool GetMessageByName(QString name,Message &m_Warning);     //获取某Led灯配置
    bool OnMessage(int m_MessageId);                            //告警触发
private:
    QVariantMap m_LedMap;                                       //配置文件map
    QMap<QString,Message> m_MessageMap;                         //存放json定义的warning
protected:
    MessageManager();
    ~MessageManager();
private:
    void Init();
    bool ReadLedJson();                                         //读取ledjson配置文件
    bool AddToMap(const QVariantMap &ledMap);                   //将json信息存入内存

};

#endif // MESSAGEMANAGER_H
