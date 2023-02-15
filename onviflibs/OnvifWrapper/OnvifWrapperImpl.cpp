#include "OnvifWrapperImpl.h"
#include "media.h"
#include "device.h"
#include <atlconv.h>

OnvifWrapperImpl::OnvifWrapperImpl(std::vector<IString*>& vec)
    : m_vecIPs(vec)
{
    int  _metadataVersion = 1;
    char* _xaddr = (char*)"http://localhost/service";
    char* _type = (char*)"\"http://schemas.xmlsoap.org/ws/2006/02/devprof\":device";
    char* _scope = (char*)"scope";
    char* _endpoint = (char*)"urn";
    discoveryObj = new DiscoveryObj(CLIENT_MODE, _metadataVersion, _xaddr, _type, _scope, _endpoint);
    //connect(discoveryObj, SIGNAL(discoveredDevice(DescDevice)), this, SLOT(onDiscoveredDevice(DescDevice)));
    discoveryObj->IEvtSet(this);
}

OnvifWrapperImpl::~OnvifWrapperImpl()
{
    delete discoveryObj;
    discoveryObj = nullptr;
}

void OnvifWrapperImpl::SendProb()
{
    m_mapDescDevice.clear();
    m_vecIPs.clear();
    discoveryObj->sendProb();
}

IString* OnvifWrapperImpl::GetMediaURL(IString* pIStrIP, uint8_t& nMaxStream)
{
    USES_CONVERSION;
    std::string strIP = W2A(pIStrIP->Get());
    qDebug() << strIP.c_str();

    if (m_mapDescDevice.find(strIP) == m_mapDescDevice.end())
        return nullptr;

    DescDevice device = m_mapDescDevice[strIP];

    qDebug() << "For device " << device.xAddrs;

    QVector<std::string> tokens = Media::getProfileTokens(device.xAddrs);
    //QVector<std::string> tokens = Media::getProfileTokens("http://172.16.6.143/onvif/media_service");
    //QVector<std::string> tokens = Media::getProfileTokens("http://127.0.0.1:8080");
    nMaxStream = tokens.size();
    /*for (int j = 0; j < tokens.size(); ++j) {
        qDebug() << "Token  " << j << "= " << tokens.at(j).data();

    }*/
    std::string strReturn;
    if (tokens.size() > 0) {
        strReturn = Media::getStreamURL(device.xAddrs, tokens.at(0)).data();
    }

    IString* pIStrReturn = _GetIStr();
    pIStrReturn->Format(_T("%s"), A2W(strReturn.c_str()));

    return pIStrReturn;
}

void OnvifWrapperImpl::GetDeviceInformation(IString* pIStrIP, std::string& strFirmwareVersion, std::string& strSerialNumber, std::string& strHardwareID, std::string& strManufacturer)
{
    USES_CONVERSION;
    std::string strIP = W2A(pIStrIP->Get());

    assert(m_mapDescDevice.find(strIP) != m_mapDescDevice.end());

    DescDevice device = m_mapDescDevice[strIP];

    Device::getDeviceInformation(device.xAddrs, strFirmwareVersion, strSerialNumber, strHardwareID, strManufacturer);
}

void OnvifWrapperImpl::onDiscoveredDevice(DescDevice dev)
{
    USES_CONVERSION;

    if (dev.xAddrs.length() == 0)
        return;

    qDebug() << "\n**********************On dev found********************";
    qDebug() << "Dev found = " << dev.xAddrs;
    qDebug() << "Dev found scope = " << dev.scopes;
    QString xAddrs = dev.xAddrs;
    qDebug() << "xAddrs : " << xAddrs;
    //xxx.remove(0, 7);
    QStringList splits = xAddrs.split('/');
    /*{
        auto iter = splits.begin();
        while (iter != splits.end())
        {
            qDebug() << *iter;
            iter++;
        }
    }*/
    QString strIP = splits[2];
    qDebug() << strIP;
    {
        QStringList strIP2 = strIP.split(":");
        strIP = strIP2[0];
    }
    std::string strString = strIP.toStdString();
    IString* pIStr = _GetIStr();
    pIStr->Format(_T("%s"), A2W(strString.c_str()));
    m_vecIPs.push_back(pIStr);
    qDebug() << strIP;


    //    QString name;
    //    char * pch = strstr((char*)dev.scopes.toStdString().data(), "OnvifVideoServer");
    //    if(pch > NULL){
    //        name = "OnvifVideoServer";
    //    }
        //ui->onvifDevCB->addItem(dev.xAddrs + " " + name, QVariant::fromValue(dev));

    //ui->onvifDevCB->addItem(dev.xAddrs + " " + dev.scopes, QVariant::fromValue(dev));
    m_mapDescDevice[strIP.toStdString()] = dev;
}
