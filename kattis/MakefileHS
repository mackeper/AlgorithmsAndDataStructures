# Makefile
# $@ : name on the left side of a : (the rule)
# $< : first name of the right side of a :

CC = runhaskell

TARGET = Main
TESTS = $(wildcard test/*.in)

run: 
	$(CC) $(TARGET).hs


# Tests in /test, donno about PHONY should google it some day...
.PHONY: clean test
test:
	@for t in $(TESTS) ; do echo $$t && \
	$(CC) $(TARGET).hs < $$t > $${t%.*}.res && \
	diff $${t%.*}.ans $${t%.*}.res || exit 0 ; done

clean:
	rm test/*.res
