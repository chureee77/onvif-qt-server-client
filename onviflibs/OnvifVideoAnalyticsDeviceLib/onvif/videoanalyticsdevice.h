#ifndef VIDEOANALYTICSDEVICE_H
#define VIDEOANALYTICSDEVICE_H

#include <QString>
#include <string>
class __declspec(dllexport) VideoAnalyticsDevice
{
public:
    VideoAnalyticsDevice();
    ~VideoAnalyticsDevice();

    static void getGetServiceCapabilities(QString devServiceURL);
};

#endif // VIDEOANALYTICSDEVICE_H
