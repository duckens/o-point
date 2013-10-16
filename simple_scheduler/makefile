CC				:= gcc
CXX				:= g++
CFLAGS			:= -I./src -I./src/scheduler
OBJECTS			:= 
LIBRARIES		:= 

SRCDIR := ./src
OBJDIR := ./obj
BINDIR := ./bin

SCHEDULERDIR := $(SRCDIR)/scheduler

all: make_directories test_scheduler_compile test_scheduler_link

test_scheduler_compile:
	$(CXX) $(CFLAGS) $(LIBRARIES) -c -o $(OBJDIR)/scheduler.o $(SCHEDULERDIR)/scheduler.cpp
	$(CXX) $(CFLAGS) $(LIBRARIES) -c -o $(OBJDIR)/schedulerTask.o $(SCHEDULERDIR)/schedulerTask.cpp
	$(CXX) $(CFLAGS) $(LIBRARIES) -c -o $(OBJDIR)/schedulerTaskExample.o $(SCHEDULERDIR)/schedulerTaskExample.cpp
	$(CXX) $(CFLAGS) $(LIBRARIES) -c -o $(OBJDIR)/testScheduler_main.o $(SCHEDULERDIR)/testScheduler_main.cpp

test_scheduler_link:
	$(CXX) $(CFLAGS) $(LIBRARIES) -o $(BINDIR)/testScheduler $(OBJDIR)/scheduler.o $(OBJDIR)/schedulerTask.o $(OBJDIR)/schedulerTaskExample.o $(OBJDIR)/testScheduler_main.o

make_directories:
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

clean:
	rm -fv $(OBJDIR)/*
	rm -fv $(BINDIR)/*

clean_all:
	rm -fv $(OBJDIR)/*
	rm -fv $(BINDIR)/*
	rm -rfv $(OBJDIR)
	rm -rfv $(BINDIR)