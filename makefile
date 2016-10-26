#Comandos para uso do makefile:
#<make> -> compilação do codigo
#<make valgrind> -> depurar e executar o codigo usando o valgrind passando os valores de entrada por input
#<make test> -> executar o codigo passando as entradas
#<make time> -> executa o codigo passando as entradas e retornando tambem o tempo de execução.
#<make clean> -> remove os arquivos .o, executavel, as estantes, o arquivo ordenado e o indice.

CC = gcc

CFLAGS = -O0 -Wall -Wextra -Werror -std=c99 -pedantic

OBJ = main.o grafo.o vini.o busca.o

DEPS = grafo.h vini.h busca.h

VFLAGS = --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes

EXEC = ./exe 

all: exe

exe: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o exe 

valgrind:
	valgrind $(VFLAGS) $(EXEC) < input

test:
	$(EXEC) < toys/in1 && cat toys/out1 && $(EXEC) < toys/in2 && cat toys/out2 && $(EXEC) < toys/in3 && cat toys/out3 && $(EXEC) < toys/in4 && cat toys/out4 && $(EXEC) < toys/in5 && cat toys/out5 && $(EXEC) < toys/in6 && cat toys/out6 && $(EXEC) < toys/in7 && cat toys/out7 && $(EXEC) < toys/in8 && cat toys/out8 && $(EXEC) < toys/in9 && cat toys/out9 && $(EXEC) < toys/in10 && cat toys/out10 

time:
	time $(EXEC) < input
