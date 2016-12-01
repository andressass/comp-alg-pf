#############################################################################
# Makefile for building: appMus
#############################################################################

CC = g++
HEADER = include/**.h
SOURCES = src/**.cpp
MUMHEADERS = MuM-master/*.h
MUMLIB = MuM-master/compiledFiles/MuM.a
all:
	$(CC) $(MUMHEADERS) $(MUMLIB) $(HEADER) $(SOURCES)
	mv a.out bin/musApp
	ln -s bin/musApp musApp
