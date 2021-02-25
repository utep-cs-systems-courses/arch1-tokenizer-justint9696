CFLAGS = -g

all: test

test: uimain.o tokenizer.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o *.c~ *.h~ *~ test

run: test
	./test
