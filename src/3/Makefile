CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
TARGET = ../../bin/lab
OS=$(shell uname)

ifeq ($(OS), Linux)
	LIBS= -lpthread -pthread -lrt -lm -lsubunit
else
	LIBS=-lcheck -pthread
endif

all: clean third_lab.a checks run

$(TARGET): third_lab.o main.o third_lab.a 
	$(CC) third_lab.o main.o -L. third_lab.a $(CFLAGS) $(LIBS) -o $@
 
main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS) $(LIBS) -o $@

third_lab.o: third_lab.cpp
	$(CC) -c third_lab.cpp $(CFLAGS) $(LIBS) -o $@

third_lab.a: third_lab.o main.o
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
	
.PHONY: all clean third_lab.a