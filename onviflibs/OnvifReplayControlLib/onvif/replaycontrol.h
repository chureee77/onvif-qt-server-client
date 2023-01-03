#ifndef REPLAYCONTROL_H
#define REPLAYCONTROL_H

#include <QString>
#include <string>
class __declspec(dllexport) ReplayControl
{
public:
    ReplayControl();
    ~ReplayControl();

    static void getGetServiceCapabilities(QString devServiceURL) ;
};

#endif // REPLAYCONTROL_H
