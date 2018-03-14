# Makefile for the EDBI Project "Análise Empirica"
# 
# Creators:
# 	- Felipe Ramos
# 	- Oziel Alves
#
# Makefile conventions
SHELL = /bin/sh

# Directories
incdir = ./include
srcdir = ./src
objdir = ./obj
bindir = ./bin

# Objects

# Macros
CC = g++
CFLAGS = -Wall -g -ggdb -std=c++11 -I. -I$(incdir)
RM = -rm
OBJS = $(addprefix $(objdir)/,util.o binary.o fibonacci.o jsearch.o sequential.o ternary.o)

# Phony targets
.PHONY: clean cleanobj cleanbin
.PHONY: all main build util binary fibonacci jsearch sequential ternary

# Use "make" to execute everything
all: build main

# Use "make main" to compile the main
main: analise

# Use "make build" to build all the modules
build: binary fibonacci jsearch sequential ternary util

# Use "make <name>" to build only the <name> module
util: $(objdir)/util.o
binary: $(objdir)/binary.o 
fibonacci: $(objdir)/fibonacci.o
jsearch: $(objdir)/jsearch.o
sequential: $(objdir)/sequential.o
ternary: $(objdir)/ternary.o

# Compiles the main
analise: $(srcdir)/main.cpp $(OBJS)
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) $^ -o $(bindir)/$@
	#$(CC) $(CFLAGS) $^ -o $@


# Builds only the util module
$(objdir)/util.o: $(srcdir)/util.cpp $(incdir)/util.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the binary module
$(objdir)/binary.o: $(srcdir)/binary.cpp $(incdir)/binary.h
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
	$(RM) -rf $(bindir)/*

clean: cleanobj cleanbin
