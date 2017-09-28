CC=gcc
CFLAGS=

DEPS = 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

s265fmt: s265fmt.o
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm *.o s265fmt
