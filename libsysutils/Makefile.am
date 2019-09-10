# Build lisysutils.so
lib_LTLIBRARIES := libsysutils.la

libsysutils_la_SOURCES  := \
                  src/SocketListener.cpp      \
                  src/FrameworkListener.cpp   \
                  src/FrameworkCommand.cpp    \
                  src/SocketClient.cpp        \
                  src/ServiceManager.cpp      \
                  EventLogTags.logtags

libsysutils_la_CPPFLAGS := -std=c++14 -std=gnu++14 -fpermissive
libsysutils_la_LDFLAGS   = @LIBLOG_LIBS@ @LIBCUTILS_LIBS@

# Export headers
sysutils_includedir=$(includedir)/sysutils
sysutils_include_HEADERS := @core_incdir@/sysutils/SocketClient.h
sysutils_include_HEADERS += @core_incdir@/sysutils/SocketClientCommand.h
sysutils_include_HEADERS += @core_incdir@/sysutils/SocketListener.h

requiredlibs = -lpthread
