# Makefile pour Battleship
# Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
# Licenced under the terms of the GLP
# Created on November 10 2014

EXEC=battleship

CC=gcc
CFLAGS=-W -Wall -std=c99 -g
NAZIFLAGS=-Wextra -pedantic
LDFLAGS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

battleship: $(OBJ)
	@$(CC) -o $@.app $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)