#
#Makefile
# $@ : name on the left side of a : (the rule)
# $< : first name of the right side of a :

CC = gcc
FLAGS = -fsanitize=undefined -g \
		-O2 -std=gnu99

TARGET = main
TESTS = $(wildcard test/*.in)

all: $(TARGET).out

$(TARGET).out : $(TARGET).c
	$(CC) $(FLAGS) -o $@ $<

run: $(TARGET).out
	./main.out


# Tests in /test, donno about PHONY should google it some day...
.PHONY: clean test
test: $(TARGET).out
	@for t in $(TESTS) ; do echo $$t && \
	./$(TARGET).out < $$t > $${t%.*}.res && \
	diff -w $${t%.*}.ans $${t%.*}.res || exit 0 ; done

clean:
	rm -f $(TARGET).out
	rm -f test/*.res
