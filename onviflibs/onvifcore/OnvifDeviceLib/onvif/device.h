#ifndef DEVICE_H
#define DEVICE_H

#include <QString>

class __declspec(dllexport) Device
{
public:
    Device();
    ~Device();
    static void getDeviceInformation(QString devServiceURL, std::string& strFirmwareVersion, std::string& strSerialNumber, std::string& strHardwareID, std::string& strManufacturer);
    static void getUses(QString devServiceURL);
};

#endif // DEVICE_H
