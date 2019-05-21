CC = g++
EXECUTABLE = priobuf
CFLAGS = -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -g
OBJS = priority-buffer.o main.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

run: $(EXECUTABLE)
	./priobuf

clean:
	rm -f $(EXECUTABLE) $(SRC)*.o
