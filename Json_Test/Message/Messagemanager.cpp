#include "MessageManager.h"
#include <mutex>

MessageManager* MessageManager::m_Manager = NULL;\

MessageManager *MessageManager::GetInstance()
{
    std::mutex mutex;
    if (m_Manager == NULL)
    {
        mutex.lock();
        m_Manager = new MessageManager();
        mutex.unlock();
    }
    return m_Manager;
}

bool MessageManager::IsExist(QString name)
{
    if(this->m_MessageMap.contains(name))
    {
        return true;
    }
    else
        return false;
}

bool MessageManager::GetMessageByName(QString name, Message &m_Message)
{
    if(this->IsExist(name))
    {
        Message tmp=this->m_MessageMap[name];
        m_Message=tmp;
        return true;
    }
    else
        return false;
}

MessageManager::MessageManager()
{

    this->Init();
    this->ReadLedJson();
}

MessageManager::~MessageManager()
{

}

void MessageManager::Init()
{
    this->m_MessageMap.clear();
}

bool MessageManager::ReadLedJson()
{
    QFile file("E:/workspace/json/json/Message.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    QString json = in.readAll();

    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject())  {
            QVariantMap result=jsonDocument.toVariant().toMap();
            foreach (QVariant plugin, result["Messages"].toList()) {
                QVariantMap ledMap= plugin.toMap();
                this->AddToMap(ledMap);
            }
            return true;
        }
        return false;
    }
    else {
        qDebug()<<"Read Led.json or parse json Faild!Please sure your json right!";
        return false;
    }
    return true;
}

bool MessageManager::AddToMap(const QVariantMap &ledMap)
{
    Message mInfo;
    mInfo.SetId(ledMap["Id"].toInt());
    mInfo.SetLedId(ledMap["LedId"].toInt());
    mInfo.SetName(ledMap["Name"].toString());
    mInfo.SetX(ledMap["X"].toInt());
    mInfo.SetY(ledMap["Y"].toInt());
    mInfo.SetWidth(ledMap["Width"].toInt());
    mInfo.SetHeight(ledMap["Height"].toInt());
    mInfo.SetColor(ledMap["Color"].toInt());
    mInfo.SetImage(ledMap["Image"].toString());
    mInfo.SetCancel(ledMap["Cancel"].toInt());
    mInfo.SetPriority(ledMap["Priority"].toInt());
    mInfo.SetBlink(ledMap["Blink"].toInt());
    mInfo.SetFrequency(ledMap["Frequency"].toInt());
    mInfo.SetMessage(ledMap["Message"].toString());
    this->m_MessageMap.insert(mInfo.GetName(),mInfo);
    return true;
}

