# Makefile for the EDBI Project "Análise Empirica"
# 
# Creators:
# 	- Felipe Ramos
# 	- Oziel Alves
# Makefile conventions
SHELL = /bin/sh

# Directories
incdir = ./include
srcdir = ./src
objdir = ./obj
bindir = ./bin

# Objects
objects = binary.o fibonacci.o jsearch.o sequential.o ternary.o # not this ones, later i can fix it

# Macros
CC = g++
CFLAGS = -Wall -g -ggdb -std=c++11 -I. -i$(incdir)
RM = -rm
OBJS = $(addprefix $(objdir)/,$(objects))

# Phony targets
.PHONY: clean cleanobj cleanbin
.PHONY: all main build binary fibonacci jsearch sequential ternary

# Use "make" to execute everything
all: build main

# Use "make main" to compile the main
main: analisar

# Use "make build" to build all the modules
build: binary fibonacci jsearch sequential ternary

# Use "make <name>" to build only the <name> module
binary: $(objdir)/binary.o 
fibonacci: $(objdir)/fibonacci.o
jsearch: $(objdir)/jsearch.o
sequential: $(objdir)/sequential.o
ternary: $(objdir)/ternary.o

# Compiles the main
analisar: $(srcdir)/main.cpp $(OBJS)
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the binary module
$(objdir)/binary.o: $(srcdir)/binary.cpp $(incdir)/util.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the fibonacci module
$(objdir)/fibonacci.o: $(srcdir)/fibonacci.cpp $(incdir)/fibonacci.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the jsearch module
$(objdir)/jsearch.o: $(srcdir)/jsearch.cpp $(incdir)/jsearch.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the sequential module
$(objdir)/sequential.o: $(srcdir)/sequential.cpp $(incdir)/sequential.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the ternary module
$(objdir)/ternary.o: $(srcdir)/ternary.cpp $(incdir)/ternary.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes all objects
cleanobj: 
	$(RM) $(objdir)/*.o

# Clean all executables
cleanbin:
	$(RM) $(bindir)/*
