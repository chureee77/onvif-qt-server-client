#ifndef EVENT_H
#define EVENT_H

#include <QString>

class __declspec(dllexport) Event
{
public:
    Event();
    ~Event();
    static void getGetServiceCapabilities(QString devServiceURL);
};

#endif // EVENT_H
