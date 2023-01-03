#ifndef RECORDINGCONTROL_H
#define RECORDINGCONTROL_H

#include <QString>
#include <string>
class __declspec(dllexport) RecordingControl
{
public:
    RecordingControl();
    ~RecordingControl();

    static void getGetServiceCapabilities(QString devServiceURL);
};

#endif // RECORDINGCONTROL_H
