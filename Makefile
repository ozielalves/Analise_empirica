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
objects = dice.o util.o chooser.o # not this ones, later i can fix it

# Macros
CC = g++
CFLAGS = -Wall -g -ggdb -std=c++11 -I. -i$(incdir)
RM = -rm
OBJS = $(addprefix $(objdir)/,$(objects))

# Phony targets
.PHONY: clean cleanobj cleanbin
.PHONY: all main build dice util chooser # change later

# Use "make" to execute everything
all: build main

# Use "make main" to compile the main
main: analisar

# Use "make build" to build all the modules
build: util dice chooser

# Use "make <name>" to build only the <name> module
util: $(objdir)/util.o 

