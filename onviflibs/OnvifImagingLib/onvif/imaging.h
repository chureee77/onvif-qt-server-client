#ifndef IMAGING_H
#define IMAGING_H

#include <QString>
#include <string>
class __declspec(dllexport) Imaging
{
public:
    Imaging();
    ~Imaging();

    static int  getGetServiceCapabilities(QString serviceURL);
};

#endif // IMAGING_H
