root_sbindir       := "/sbin"
root_sbin_PROGRAMS := leprop-service

leprop_service_SOURCES  = property_service.c
leprop_service_SOURCES += ll.c

leprop_service_CPPFLAGS = -I$(top_srcdir) @LIBCUTILS_CFLAGS@
leprop_service_LDFLAGS  = @LIBLOG_LIBS@ @LIBCUTILS_LIBS@

if PROPTRIGGER
leprop_service_CPPFLAGS += -DPROP_TRIGGER

root_etcdir      := "/etc/"
root_etc_SCRIPTS := proptrigger.sh
root_etc_SCRIPTS += proptrigger.conf

install-data-hook:
	chmod  go-x $(DESTDIR)$(root_etcdir)/proptrigger.sh
	chmod  go-x $(DESTDIR)$(root_etcdir)/proptrigger.conf
endif
