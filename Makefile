CC = gcc
CFLAGS = -W -Wall -pedantic -std=c11
LFLAGS = -lm
SRC = $(wildcard *.c) 
BIN = $(SRC:.c=)

.PHONY: all clear help

help:
	@echo "Sintaxe: make <opção>"
	@echo "	Opções:"
	@echo "		help	: mostra esta mensagem"
	@echo "		all	: compila todos os fontes da pasta"
	@echo "		clear	: apaga todos os bin criados"
	@echo ""

all: $(BIN)

clear:
	@rm -f $(BIN)

%:%.c
	@echo -n "Gerando executavel $@"
	@$(CC) $< -o $@ $(CFLAGS) $(LFLAGS) && echo " [OK]"
