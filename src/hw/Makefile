CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
TARGET = ../../bin/lab
OS=$(shell uname)

ifeq ($(OS), Linux)
	LIBS= -lpthread -pthread -lrt -lm -lsubunit
else
	LIBS=-lcheck -pthread
endif

all: clean first_hw.a checks run

$(TARGET): first_hw.o main.o first_hw.a 
	$(CC) first_hw.o main.o -L. first_hw.a $(CFLAGS) $(LIBS) -o $@
 
main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS) $(LIBS) -o $@

first_hw.o: first_hw.cpp
	$(CC) -c first_hw.cpp $(CFLAGS) $(LIBS) -o $@

first_hw.a: first_hw.o main.o
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
	
.PHONY: all clean first_hw.a