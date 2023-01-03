#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <QString>
#include <string>
class __declspec(dllexport) Analytics
{
public:
    Analytics();
    ~Analytics();

    static void getGetServiceCapabilities(QString devServiceURL);
};

#endif // ANALYTICS_H
