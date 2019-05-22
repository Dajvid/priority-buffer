CC = g++
EXECUTABLE = priobuf
CFLAGS = -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -g
SRC = ../src/
OBJS =  priority-buffer.o main.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: $(SRC)%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(SRC)*.o
