CC=gcc
CXX=g++
RM=rm -f

SRCS=main.cpp batch.cpp dataSet.cpp fileManager.cpp analyzer.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) -o main $(OBJS)

main.o: main.cpp fileManager.h dataSet.h batch.h analyzer.h

batch.o: batch.cpp fileManager.h

dataSet.o: dataSet.cpp batch.h fileManager.h

fileManager.o: fileManager.cpp

analyzer.o: analyzer.cpp dataSet.h batch.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) tool