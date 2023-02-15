#include "OnvifWrapper.h"
#include "OnvifWrapperImpl.h"

OnvifWrapper::OnvifWrapper(std::vector<IString*>& vec)
{
	m_pWrapper = new OnvifWrapperImpl(vec);
}

OnvifWrapper::~OnvifWrapper()
{
	delete m_pWrapper;
}

void OnvifWrapper::SendProb()
{
	m_pWrapper->SendProb();
}

IString* OnvifWrapper::GetMediaURL(IString* strIP, uint8_t& nMaxStream)
{
	return m_pWrapper->GetMediaURL(strIP, nMaxStream);
}

void OnvifWrapper::GetDeviceInformation(IString* strIP, std::string& strFirmwareVersion, std::string& strSerialNumber, std::string& strHardwareID, std::string& strManufacturer)
{
	m_pWrapper->GetDeviceInformation(strIP, strFirmwareVersion, strSerialNumber, strHardwareID, strManufacturer);
}