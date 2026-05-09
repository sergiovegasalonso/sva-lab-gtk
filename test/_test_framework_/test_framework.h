#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

// includes
#include <glib.h>
#include <stdio.h>

// variables
extern int tests_passed;
extern int tests_failed;
extern int total_tests;

// types
typedef gboolean (*TestFunc)(void);

// functions
void run_test_impl(TestFunc fn, const char *name);

// macros
#define TEST_ASSERT(condition, message)                                        \
  do {                                                                         \
    if (!(condition)) {                                                        \
      g_error("FAILED: %s - %s", __func__, message);                           \
      return FALSE;                                                            \
    } else {                                                                   \
      g_print("PASSED: %s - %s\n", __func__, message);                         \
    }                                                                          \
  } while (0)

#define RUN_TEST(test_func) run_test_impl((test_func), #test_func)

#endif // TEST_FRAMEWORK_H