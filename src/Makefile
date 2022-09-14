CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
TARGET = bin/lab
OS=$(shell uname)

ifeq ($(OS), Linux)
	LIBS= -lpthread -pthread -lrt -lm -lsubunit
else
	LIBS=-lcheck -pthread
endif

all: clean first_lab.a checks

$(TARGET): first_lab.o array_processing_methods.o main.o first_lab.a 
	$(CC) first_lab.o array_processing_methods.o main.o -L. first_lab.a $(CFLAGS) $(LIBS) -o $@

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS) $(LIBS) -o $@

first_lab.o: first_lab.cpp
	$(CC) -c first_lab.cpp $(CFLAGS) $(LIBS) -o $@

array_processing_methods.o: array_processing_methods.cpp
	$(CC) -c array_processing_methods.cpp $(CFLAGS) $(LIBS) -o $@

first_lab.a: first_lab.o array_processing_methods.o main.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

run: clean $(TARGET)
	./bin/lab

clean:	
	rm -rf first_lab  
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info

rebuild: clean all

checks:
	python3 ../materials/linters/cpplint.py *.cpp *.h
	
.PHONY: all clean first_lab.a