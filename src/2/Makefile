CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
TARGET = ../../bin/lab
OS=$(shell uname)

ifeq ($(OS), Linux)
	LIBS= -lpthread -pthread -lrt -lm -lsubunit
else
	LIBS=-lcheck -pthread
endif

all: clean second_lab.a checks run

$(TARGET): second_lab.o main.o second_lab.a 
	$(CC) second_lab.o main.o -L. second_lab.a $(CFLAGS) $(LIBS) -o $@
 
main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS) $(LIBS) -o $@

second_lab.o: second_lab.cpp
	$(CC) -c second_lab.cpp $(CFLAGS) $(LIBS) -o $@

second_lab.a: second_lab.o main.o
	ar rcs $@ $^
	ranlib $@

run: clean $(TARGET)
	./$(TARGET)

clean:	
	rm -rf ../../bin/lab
	rm -rf *.o *.so *.a *.gc* *.info report *.out *.gcda *.so *.gcno *.info
	rm -rf ../*.o ../*.so ../*.a ../*.gc* ../*.info ../report ../*.out ../*.gcda ../*.so ../*.gcno ../*.info

rebuild: clean all

checks:
	python3 ../../materials/linters/cpplint.py *.cpp *.h
	
.PHONY: all clean second_lab.a