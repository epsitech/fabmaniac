# file Makefile
# make file for Fmnc combined daemon, release fmnccmbd_genio
# author Alexander Wirthmueller
# date created: 7 Mar 2016
# modified: 7 Mar 2016

SRCROOT = /home/epsi/src
LIBROOT = /home/epsi/lib
BINROOT = /home/epsi/bin

CC = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DFMNCCMBD
LDFLAGS =

INCS = -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include -I/usr/include
INCS += -I$(SRCROOT)
INCS += -I$(SRCROOT)/dbsfmnc
INCS += -I$(SRCROOT)/fmnccmbd -I$(SRCROOT)/fmnccmbd/IexFmnc -I$(SRCROOT)/fmnccmbd/VecFmnc
INCS += -I$(SRCROOT)/fmnccmbd/CrdFmncNav -I$(SRCROOT)/fmnccmbd/CrdFmncUsg -I$(SRCROOT)/fmnccmbd/CrdFmncUsr -I$(SRCROOT)/fmnccmbd/CrdFmncOrg -I$(SRCROOT)/fmnccmbd/CrdFmncPrs -I$(SRCROOT)/fmnccmbd/CrdFmncAdr -I$(SRCROOT)/fmnccmbd/CrdFmncFil -I$(SRCROOT)/fmnccmbd/CrdFmncStp -I$(SRCROOT)/fmnccmbd/CrdFmncPrj -I$(SRCROOT)/fmnccmbd/CrdFmncRun -I$(SRCROOT)/fmnccmbd/CrdFmncAct -I$(SRCROOT)/fmnccmbd/CrdFmncSep -I$(SRCROOT)/fmnccmbd/CrdFmncSmp -I$(SRCROOT)/fmnccmbd/CrdFmncFab -I$(SRCROOT)/fmnccmbd/CrdFmncFus -I$(SRCROOT)/fmnccmbd/CrdFmncTty -I$(SRCROOT)/fmnccmbd/CrdFmncTol -I$(SRCROOT)/fmnccmbd/CrdFmncFpj -I$(SRCROOT)/fmnccmbd/CrdFmncBil -I$(SRCROOT)/fmnccmbd/CrdFmncArt -I$(SRCROOT)/fmnccmbd/CrdFmncSki -I$(SRCROOT)/fmnccmbd/CrdFmncPco
INCS +=

LIBS = -L$(LIBROOT)/fmnccmbd
LIBS += -lcrdfmncnav -lcrdfmncusg -lcrdfmncusr -lcrdfmncorg -lcrdfmncprs -lcrdfmncadr -lcrdfmncfil -lcrdfmncstp -lcrdfmncprj -lcrdfmncrun -lcrdfmncact -lcrdfmncsep -lcrdfmncsmp -lcrdfmncfab -lcrdfmncfus -lcrdfmnctty -lcrdfmnctol -lcrdfmncfpj -lcrdfmncbil -lcrdfmncart -lcrdfmncski -lcrdfmncpco
LIBS +=
LIBS += -liexfmnc
LIBS += -L$(LIBROOT)
LIBS += -ldbsfmnc -lvecfmnc
LIBS += -ldartdbsengcore
LIBS += -ldbsdemn
LIBS += -L/usr/lib -lxml2
LIBS += -lmysqlclient
LIBS += -lpq
LIBS += -L/usr/local/lib -lmicrohttpd
LIBS += -lcurl
LIBS += -L/lib/x86_64-linux-gnu/libpthread -lpthread

PCHS = Fmnccmbd.h.gch

OBJECTS = Fmnc.o FmnccmbdAppsrv.o FmnccmbdJobprc.o FmnccmbdOpprc.o Fmnccmbd.o
OBJECTS += RootFmnc.o SessFmnc.o
OBJECTS += Fmnccmbd_exe.o

EXE = Fmnccmbd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CC) $(CPPFLAGS) $(INCS) -o $@ -c $<

.cpp.o :
	$(CC) $(CPPFLAGS) $(INCS) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(EXE)
	rm -f *.o

pch:	$(PCHS)

install:
	cp $(EXE) $(BINROOT)/fmnccmbd/

clean:
	rm -f *.gch
	rm -f *.o

