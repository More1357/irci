CC = gcc
CFLAGS = -Wall -Wextra -O2 -g
TARGET = procesador
OBJS = main.o cpu.o memoria.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c cpu.h memoria.h
	$(CC) $(CFLAGS) -c main.c

cpu.o: cpu.c cpu.h memoria.h
	$(CC) $(CFLAGS) -c cpu.c

memoria.o: memoria.c memoria.h
	$(CC) $(CFLAGS) -c memoria.c

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	gdb ./$(TARGET)

.PHONY: all clean run debug