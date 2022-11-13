CC = g++
GCOV_TEST = gcov_report
TARGET = FastMultiplying
GTEST =`pkg-config --cflags --libs gtest`
CFLAGS = -std=c++17 -Wall -Werror -Wextra -lstdc++
TESTTARGET = tests/tests.cc

GCOV = --coverage

all: clang-format $(TARGET)
	./$(TARGET)

$(TARGET):      
	$(CC) $(CFLAGS) CP_evalution.cc matrix.cc -o $@

tests: gcov_report

clang-format: 
	clang-format -i *.cc *.h
	clang-format -n *.cc *.h

gcov_report:
	$(CC) $(GCOV) $(CFLAGS) -c matrix.cc CP_evalution.cc $(LIBS)
	$(CC) $(GCOV) $(CFLAGS) $(LIBS) -c $(TESTTARGET) $(LIBS)
	$(CC) $(GCOV) $(CFLAGS) $(LIBS) *.o -o $(GCOV_TEST) $(GTEST)
	./$(GCOV_TEST)
	gcov $(TESTTARGET)
	lcov -t $(GCOV_TEST) --no-external -o $(GCOV_TEST).info -c -d .
	genhtml -o report $(GCOV_TEST).info
	google-chrome ./report/index.html

clean:	
	rm -rf FastMultiplying
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info gcov_report

.PHONY: all re test gcov_report clean clean_gcov