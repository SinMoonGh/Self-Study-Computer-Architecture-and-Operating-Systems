CC = gcc
TARGET = manage_system
OBJS = manage_system.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

%.o: %.c
	$(CC) -c $<

clean:
	rm -f *.o $(TARGET)
