CC=gcc

DEPS = 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< -ansi

s265fmt: s265fmt.o
	$(CC) -o $@ $^ -ansi

.PHONY: clean

clean:
	rm *.o s265fmt
