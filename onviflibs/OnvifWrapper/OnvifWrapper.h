#pragma once

#include <vector>
#include <string>
#include "D:\\Project\inc\StdIV.h"

#ifndef BUILD_STATIC
# if defined(ONVIFWRAPPER_LIB)
#  define ONVIFWRAPPER_EXPORT __declspec(dllexport)
# else
#  define ONVIFWRAPPER_EXPORT __declspec(dllimport)
# endif
#else
# define ONVIFWRAPPER_EXPORT
#endif

class OnvifWrapperImpl;
class ONVIFWRAPPER_EXPORT OnvifWrapper : public CStdIV
{
public:
    OnvifWrapper(std::vector<IString*>& vec);
    ~OnvifWrapper();

public:
    void SendProb();
    IString* GetMediaURL(IString* strIP, uint8_t& nMaxStream);
    void GetDeviceInformation(IString* strIP, std::string& strFirmwareVersion, std::string& strSerialNumber, std::string& strHardwareID, std::string& strManufacturer);

private:
    OnvifWrapperImpl* m_pWrapper = nullptr;
};
