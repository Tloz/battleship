# Makefile pour battleship
# Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
# Licenced under the terms of the GLP
# Created on November 08 2014
# Description

# project name (generate executable with this name)
TARGET   = battleship.app

CC       = g++
# compiling flags here
CFLAGS   = -Wall -I. -std=c++11 -fpermissive

LINKER   = g++ -o
# linking flags here
LFLAGS   = -Wall -I. -lm -std=c++11 -fpermissive

# change these to set the proper directories where each files shoould be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"