CC=g++
CFLAGS=-I. -g
DEPS = SimNode.hh Timeline.hh DataPath.hh ComputeNode.hh
OBJ = main.o SimNode.o Timeline.o DataPath.o ComputeNode.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *~ *.o
