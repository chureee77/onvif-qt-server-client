TEMPLATE = subdirs

INCLUDEPATH += D:\Project\inc

SUBDIRS +=  onvifcore/OnvifDeviceLib \
            onvifcore/OnvifDiscoveryLib \
            onvifcore/OnvifEventLib \
            OnvifAnalyticsLib \
           # OnvifDeviceIOLib \
            OnvifDisplayLib \
            OnvifImagingLib \
            OnvifMediaLib \
            OnvifPTZLib \
            OnvifReceiverLib \
            OnvifRecordingControlLib \
            OnvifRecordingSearchLib \
            OnvifReplayControlLib \
            OnvifVideoAnalyticsDeviceLib

QMAKE_CXXFLAGS += /bigobj

