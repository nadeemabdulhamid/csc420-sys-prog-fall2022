#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my_strtok.h"

static int total_tests = 0;
static int num_correct = 0;
static int num_incorrect = 0;

#define USAGE "\"./run_tests\" runs strtok tests"
void assert_equal_str(char* expected, char* actual, const char* message);

// Runs tests for my_strtok
void test_strtok() {
  char str[80] = "1,2,,3,4";
  const char s[2] = ",";
  assert_equal_str("1", my_strtok(str, s),
                   "strtok(\"1,2,,3,4\", \",\") first time");
  assert_equal_str("2", my_strtok(NULL, s),
                   "strtok(\"1,2,,3,4\", \",\") second time");
  assert_equal_str("3", my_strtok(NULL, s),
                   "strtok(\"1,2,,3,4\", \",\") third time");
  assert_equal_str("4", my_strtok(NULL, s),
                   "strtok(\"1,2,,3,4\", \",\") fourth time");
  assert_equal_str(NULL, my_strtok(NULL, s),
                   "strtok(\"1,2,,3,4\", \",\") fifth time");

  char str2[80] = ";;;33;;6;;77;";
  const char d[3] = ";;";
  assert_equal_str("33", my_strtok(str2, d),
                   "strtok(\";;;33;;6;;77;\", \";;\") first time");
  assert_equal_str("6", my_strtok(NULL, d),
                   "strtok(\";;;33;;6;;77;\", \";;\") second time");
  assert_equal_str("77", my_strtok(NULL, d),
                   "strtok(\";;;33;;6;;77;\", \";;\") third time");
  assert_equal_str(NULL, my_strtok(NULL, d),
                   "strtok(\";;;33;;6;;77;\", \";;\") fourth time");
}

// checks if the actual string is the expected string, and returns an
// error message if not
void assert_equal_str(char* expected, char* actual, const char* message) {
  ++total_tests;

  if (expected == NULL || actual == NULL) {
    if (expected == NULL && actual == NULL) {
      ++num_correct;
    } else {
      ++num_incorrect;
      printf("[FAILED Test %d: %s]: Expected %s, actual %s\n", total_tests,
             message, expected, actual);
    }
    return;
  }

  if (!strcmp(expected, actual)) {
    ++num_correct;
  } else {
    ++num_incorrect;
    printf("[FAILED Test %d: %s]: Expected %s, actual %s\n", total_tests,
           message, expected, actual);
  }
}

// prints a summary based on the number of tests passed and failed
void print_test_summary() {
  printf("Passed %d tests, Failed %d tests | %f%%\n", num_correct,
         num_incorrect,
         100 * ceil((float)num_correct) / (total_tests == 0 ? 1 : total_tests));
  total_tests = 0;
  num_incorrect = 0;
  num_correct = 0;
}

// runs the function passed in and prints a test summary
void run_test(void (*func)(), const char* message) {
  printf("=================== Running %s Tests. ===================\n",
         message);
  func();
  printf("%s: ", message);
  print_test_summary();
}

int main(int argc, char const* argv[]) {
  printf("Testing for correctness...\n");

  if (argc > 1) {
    printf("USAGE: %s\n", USAGE);
    return 1;
  }

  // passes the function test_strtok to run_test
  run_test(&test_strtok, "strtok");

  return 0;
}
