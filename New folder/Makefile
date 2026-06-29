
CC      = gcc
CFLAGS  = -Wall -Wextra -g
TARGET  = apc
SRCS    = main.c dll.c addition.c subtraction.c multiplication.c division.c
OBJS    = $(SRCS:.c=.o)
 
all: $(TARGET)
 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
 
%.o: %.c apc.h
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJS) $(TARGET)
 
.PHONY: all clean
 