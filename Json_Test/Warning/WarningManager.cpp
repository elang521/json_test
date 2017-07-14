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

bool WarningManager::IsExist(QString name)
{
    if(this->m_WarningMap.contains(name))
    {
        return true;
    }
    else
        return false;
}

bool WarningManager::GetWarningByName(QString name, Warning &m_Warning)
{
    if(this->IsExist(name))
    {
        Warning tmp=this->m_WarningMap[name];
        m_Warning=tmp;
        return true;
    }
    else
        return false;
}

WarningManager::WarningManager()
{

    this->Init();
    this->ReadLedJson();
}

WarningManager::~WarningManager()
{

}

void WarningManager::Init()
{
    this->m_WarningMap.clear();
}

bool WarningManager::ReadLedJson()
{
    QFile file("E:/workspace/json/json/Warning.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    QString json = in.readAll();

    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject())  {
            QVariantMap result=jsonDocument.toVariant().toMap();
            foreach (QVariant plugin, result["Warnings"].toList()) {
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

bool WarningManager::AddToMap(const QVariantMap &ledMap)
{
    Warning mInfo;
    mInfo.SetId(ledMap["Id"].toInt());
    mInfo.SetLedId(ledMap["LedId"].toInt());
    mInfo.SetName(ledMap["Name"].toString());
    mInfo.SetX(ledMap["X"].toInt());
    mInfo.SetY(ledMap["Y"].toInt());
    mInfo.SetWidth(ledMap["Width"].toInt());
    mInfo.SetHeight(ledMap["Height"].toInt());
    mInfo.SetColor(ledMap["Color"].toInt());
    mInfo.SetImage(ledMap["Image"].toString());
    mInfo.SetSound(ledMap["Sound"].toString());
    mInfo.SetMovie(ledMap["Movie"].toString());
    mInfo.SetCancel(ledMap["Cancel"].toInt());
    mInfo.SetResourceX(ledMap["ResourceX"].toInt());
    mInfo.SetResourceY(ledMap["ResourceY"].toInt());
    mInfo.SetPriority(ledMap["Priority"].toInt());
    mInfo.SetBlink(ledMap["Blink"].toInt());
    mInfo.SetFrequency(ledMap["Frequency"].toInt());
    mInfo.SetMessage(ledMap["Message"].toString());
    this->m_WarningMap.insert(mInfo.GetName(),mInfo);
    return true;
}

