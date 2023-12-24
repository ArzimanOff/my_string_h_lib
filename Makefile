CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -std=c11
LFLAGS = -Wall -Werror -Wextra -g -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector -fanalyzer
COVFLAGS = -fprofile-arcs -ftest-coverage
TESTFLAGS = -lcheck
FILES= $(wildcard s21_string_funcs/s21_*.c)
TESTFILE = test.c

UNAME = $(shell uname -s)
FLAGS =

ifeq ($(UNAME), Linux)
	FLAGS += -lcheck -lm -lsubunit -lrt -lpthread
else
	FLAGS += -lcheck
endif

all: test_string


s21_string.a: s21_string.o
	ar rc s21_string.a *.o
	ranlib s21_string.a
	rm *.o

s21_string.o: $(FILES) s21_string_funcs/s21_string.h
	$(CC) $(CFLAGS) -c $(FILES)

test_string: s21_string.o
	$(CC) $(CFLAGS) $(TESTFILE) $(FILES) $(TESTFLAGS) -o test_string

string: s21_string.o
	$(CC) $(CFLAGS) $(TESTFILE) $(FILES) $(TESTFLAGS) -o test


style:
	clang-format -i -style=Google s21_string_funcs/*.c s21_string_funcs/*.h


leaks: s21_string.a
	clear
	$(CC) $(CFLAGS) $(TESTFILE) s21_string.a -o v
	valgrind --tool=memcheck --leak-check=yes ./v
	leaks -atExit -- ./v
	$(CC) $(LFLAGS) $(TESTFILE) s21_string.a -o 1
	./1


gcov_report:
	$(CC) $(CFLAGS) $(TESTFILE) $(FILES) $(TESTFLAGS) $(COVFLAGS) -o test_string
	./test_string
	lcov -t "String_tests" -o test.info -c -d .
	genhtml -o report test.info
	rm *.gcda *.gcno *.info
	open report/index.html


clean:
	rm -rf test_string *.o *.a *.gch *gcda report *gcno *info test_string.dSYM

rebuild: clean all

.PHONY: all test_string gcov_report style clean s21_string.a
