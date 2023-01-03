#ifndef RECORDINGSEARCH_H
#define RECORDINGSEARCH_H

#include <QString>
#include <string>
class __declspec(dllexport) RecordingSearch
{
public:
    RecordingSearch();
    ~RecordingSearch();

    static void getGetServiceCapabilities(QString devServiceURL);
};

#endif // RECORDINGSEARCH_H
