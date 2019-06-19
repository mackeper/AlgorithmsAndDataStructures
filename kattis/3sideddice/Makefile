# Makefile

CC = swipl
FLAGS = -O -q -g main -t halt -c

TARGET = a
TESTS = $(wildcard test/*.in)

all: $(TARGET).out

$(TARGET).out:
	$(CC) $(FLAGS) kattio.pl main.pl

run: $(TARGET).out
	./a.out

# Tests in /test, donno about PHONY should google it some day...
.PHONY: clean test
test: $(TARGET).out
	@for t in $(TESTS) ; do echo $$t && \
	./$(TARGET).out < $$t > $${t%.*}.res && \
	diff -w $${t%.*}.ans $${t%.*}.res || exit 0 ; done

clean:
	rm $(TARGET).out
	rm test/*.res
