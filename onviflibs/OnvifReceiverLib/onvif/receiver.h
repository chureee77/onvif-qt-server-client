#ifndef RECEIVER_H
#define RECEIVER_H

#include <QString>
#include <string>
class __declspec(dllexport) Receiver
{
public:
    Receiver();
    ~Receiver();

    static QVector<std::string>  getGetReceivers(QString devServiceURL);
};

#endif // RECEIVER_H
