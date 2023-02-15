#pragma once

#include <QtCore/qglobal.h>
#include <qdebug.h>
#include "descdevice.h"
#include "discoveryobj.h"
#include "d:\Project\inc\StdIV.h"

class OnvifWrapperImpl : /*public QObject, */public IEvtDiscoveryObj, public CStdIV
{
	//Q_OBJECT

	//////////////////
	//IEvtDiscoveryObj
	//////////////////
protected:
	virtual void discoveredDevice(DescDevice device)
	{
		onDiscoveredDevice(device);
	}

public:
	OnvifWrapperImpl(std::vector<IString*>& vec);
	~OnvifWrapperImpl();

private:
	std::vector<IString*>& m_vecIPs;
public:
	void SendProb();
	IString* GetMediaURL(IString* pIStrIP, uint8_t& nMaxStream);
	void GetDeviceInformation(IString* pIStrIP, std::string& strFirmwareVersion, std::string& strSerialNumber, std::string& strHardwareID, std::string& strManufacturer);

private:
	DiscoveryObj* discoveryObj = NULL;

private:
	std::map< std::string, DescDevice> m_mapDescDevice;
private/* slots*/:
	void onDiscoveredDevice(DescDevice);
};

