root_sbindir       := "/sbin"
root_sbin_PROGRAMS := logd

logd_SOURCES = main.cpp \
    LogCommand.cpp \
    CommandListener.cpp \
    LogListener.cpp \
    LogReader.cpp \
    FlushCommand.cpp \
    LogBuffer.cpp \
    LogBufferElement.cpp \
    LogTimes.cpp \
    LogStatistics.cpp \
    LogWhiteBlackList.cpp \
    libaudit.c \
    LogAudit.cpp \
    LogKlog.cpp \
    event.logtags

logd_CPPFLAGS  = -I$(top_srcdir)/include
logd_CPPFLAGS += -I$(top_srcdir)/base/include
logd_CPPFLAGS += -std=c++14 -std=gnu++14
logd_CPPFLAGS += -fpermissive -fms-extensions
logd_CPPFLAGS += -DAUDITD_LOG_TAG=1003 -DLOGD_LOG_TAG=1004
logd_CPPFLAGS += -DHAVE_ANDROID_OS

logd_LDFLAGS  = -lpthread -lsysutils
logd_LDFLAGS += @LIBBASE_LIBS@ @LIBLOG_LIBS@
logd_LDFLAGS += @LIBUTILS_LIBS@ @LIBCUTILS_LIBS@
