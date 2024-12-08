all: clean test

.PHONY: test
test: $(OBJS)
	$(CC) strtok_escaped.c test.c -std=c99 -Wall -Werror -o test
	./test

.PHONY: clean
clean:
	rm -f test

.PHONY: format
format:
	# pip install clang-format
	clang-format -i *.c
	clang-format -i *.h
