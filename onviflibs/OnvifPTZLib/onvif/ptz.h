#ifndef PTZ_H
#define PTZ_H

#include <QString>
class __declspec(dllexport) PTZ
{
public:
    PTZ();
    ~PTZ();
    static void getStatus(QString devServiceURL);
    static void getNodes(QString devServiceURL);
    static void goToPreset(QString devServiceURL);
};

#endif // PTZ_H
