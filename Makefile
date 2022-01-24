.POSIX:
.PHONY: clean

test: test.o snd.o
	${CC} -o $@ test.o snd.o -lm

clean:
	rm -f *.o test *.au
