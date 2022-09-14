CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
TESTTARGET = test/s21_test_matrix_oop
OS=$(shell uname)

ifeq ($(OS), Linux)
	LIBS= -lgtest -lpthread -pthread -lrt -lm -lsubunit
	LEAKS= valgrind --track-origins=yes --leak-check=full  ./test/s21_test_matrix_oop
else
	LIBS=-lcheck -lgtest -pthread
	LEAKS=leaks --atExit -- ./test/s21_test_matrix_oop
endif

all: clean s21_matrix_oop.a test checks

$(TARGET): s21_matrix_oop.o s21_matrix_oop.a
	$(CC) s21_matrix_oop.o -L. s21_matrix_oop.a $(CFLAGS) $(LIBS) -o $@

s21_matrix_oop.o: s21_matrix_oop.cpp
	$(CC) -c s21_matrix_oop.cpp $(CFLAGS) $(LIBS) -o $@

s21_matrix_oop.a: s21_matrix_oop.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

run: clean start

start:
	g++ s21_matrix_oop.cpp $(CFLAGS) -lm
	./a.out

$(TESTTARGET): s21_matrix_oop.a test/s21_test_matrix_oop.o s21_matrix_oop.o
	$(CC) test/s21_test_matrix_oop.cpp s21_matrix_oop.o $(LIBS) -o $@

test/s21_test_matrix_oop.o: test/s21_test_matrix_oop.cpp s21_matrix_oop.h
	$(CC) -c test/s21_test_matrix_oop.cpp $(LIBS)  -o $@ 
	$(CC) -c s21_matrix_oop.cpp -lgtest $(LIBS) -o $@

test: $(TESTTARGET)
	./$(TESTTARGET)

clean:	
		rm -rf s21_test_matrix_oop s21_matrix_oop 
		rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
		rm -rf test/*.o test/*.so test/*.a  test/*.gcda  test/*.so  test/*.gcno  test/*.info test/s21_test_matrix_oop

rebuild: clean all

checks:
	$(LEAKS)
	python3 ../materials/linters/cpplint.py *.cpp *.h
	
.PHONY: all clean test s21_matrix_oop.a