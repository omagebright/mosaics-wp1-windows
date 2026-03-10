#===============================================================================
# Header
CD = cd
MAKE = make
INCL = utils
#===============================================================================
# Compiler Definitoins 
#CC = g++ -g
#CC = g++ -Wno-deprecated -I$(INCL)
CC = g++ -I$(INCL) -I.
#===============================================================================
LLIB = -lm
#===============================================================================
# Top directory
TOPDIR = ..
#===============================================================================
# Additional Source Directories
EXE = $(TOPDIR)/runnable
#===============================================================================
# OBJECT files
OBJS = mcmc.o ran1.o mb.o potentials.o   \
       statistics.o partition.o output.o \
       title.o utillib.o parse_input.o
#===============================================================================
# Create executable file eemc.x
all: $(EXE)/mcmc.exe
#===============================================================================
# CREATE mcmc.x  
$(EXE)/mcmc.exe: $(OBJS)
	$(CC) -o $(EXE)/mcmc.exe $(OBJS) $(LLIB)
#===============================================================================
# MATHLIB 
ran1.o : ran1.cpp
	$(CC) -c -o ran1.o ran1.cpp
mb.o : mb.cpp
	$(CC) -c -o mb.o mb.cpp
potentials.o : potentials.cpp
	$(CC) -c -o potentials.o potentials.cpp
mcmc.o : mcmc.cpp
	$(CC) -c -o mcmc.o mcmc.cpp
statistics.o : statistics.cpp
	$(CC) -c -o statistics.o statistics.cpp
partition.o : partition.cpp
	$(CC) -c -o partition.o partition.cpp
output.o : output.cpp
	$(CC) -c -o output.o output.cpp
title.o : title.cpp
	$(CC) -c -o title.o title.cpp
parse_input.o : parse_input.cpp
	$(CC) -c -o parse_input.o parse_input.cpp
utillib.o : utillib.cpp
	$(CC) -c -o utillib.o utillib.cpp
#===============================================================================
# IMPLICIT RULES
clean :  
	rm $(OBJS) 

