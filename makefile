CC = gcc
CFLAGS = -Iinclude -Wall

SRC = $(wildcard src/*.c)      # Trouve tous les fichiers .c dans src/
OBJ = $(SRC:.c=.o)            # Remplace l'extension .c par .o

banking_system.exe: $(OBJ)
	$(CC) -o banking_system.exe $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q src\*.o bank_manage.exe
