CFLAGS = -Wall -Werror -Wextra -std=c11
LIB_FLAGS = -L ./ -l:s21_string.a
TEST_FLAGS = -lcheck -lm -lsubunit
TEST_FILES = tests/*.c
FILES = ${wildcard *.c}
OBJECTS = ${patsubst %.c, %.o, ${FILES}}
LD_FLAGS :=

all:
	${MAKE} clean
	$(MAKE) s21_string.a

s21_string.a: ${OBJECTS}
	ar r s21_string.a ${OBJECTS}
	rm -rf *.o

%.o: %.c
	gcc ${CFLAGS} -c $< -o $@ ${LD_FLAGS}

clang:
	clear
	clang-format -n *.c *.h ${TEST_FILES} tests/*.h
	clang-format -i *.c *.h ${TEST_FILES} tests/*.h

test: s21_string.a
	gcc $(TEST_FILES) $(CFLAGS) $(TEST_FLAGS) ${LIB_FLAGS} ${LD_FLAGS}
	./a.out
	rm -rf *.out

gcov_report: LD_FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: clean test
	lcov --directory . --capture --branch-coverage --output-file coverage.info
	genhtml coverage.info --branch-coverage --output-directory coverage_report
	xdg-open coverage_report/index.html
	rm -rf *.gcda *.gcno *.o
	rm -rf coverage.info test_executable

clean:
	clear
	rm -rf *.out *.o *.a
	rm -rf *.gcda *.gcno
	rm -rf coverage_report coverage.info
