#ifndef DISPLAY_H
#define DISPLAY_H

#include <QString>
#include <string>
class __declspec(dllexport) Display
{
public:
    Display();
    ~Display();

    static void getGetServiceCapabilities(QString devServiceURL) ;
};

#endif // DISPLAY_H
