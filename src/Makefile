CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
TARGET = ../bin/lab
OS=$(shell uname)

ifeq ($(OS), Linux)
	LIBS= -lpthread -pthread -lrt -lm -lsubunit
else
	LIBS=-lcheck -pthread
endif

all: clean 1/first_lab.a checks run

$(TARGET): 1/first_lab.o array_processing_methods.o 1/main.o 1/first_lab.a 
	$(CC) 1/first_lab.o array_processing_methods.o 1/main.o -L. 1/first_lab.a $(CFLAGS) $(LIBS) -o $@
 
1/main.o: 1/main.cpp
	$(CC) -c 1/main.cpp $(CFLAGS) $(LIBS) -o $@

1/first_lab.o: 1/first_lab.cpp
	$(CC) -c 1/first_lab.cpp $(CFLAGS) $(LIBS) -o $@

array_processing_methods.o: array_processing_methods.cpp
	$(CC) -c array_processing_methods.cpp $(CFLAGS) $(LIBS) -o $@

1/first_lab.a: 1/first_lab.o array_processing_methods.o 1/main.o
	ar rcs $@ $^
	ranlib $@

run: clean $(TARGET)
	./$(TARGET)

clean:	
	rm -rf ../bin/lab 
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info

rebuild: clean all

checks:
	python3 ../materials/linters/cpplint.py *.cpp *.h
	
.PHONY: all clean 1/first_lab.a