CC=gcc

DEPS = 

%.o: %.c $(DEPS)
	$(CC) -c -o bin/$@ $< -ansi

s265fmt: s265fmt.o
	$(CC) -o bin/$@ bin/$^ -ansi

.PHONY: clean

clean:
	rm bin/*.o bin/s265fmt
