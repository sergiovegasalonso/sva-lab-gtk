#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <glib.h>
#include <stdio.h>

// Test framework macros
#define TEST_ASSERT(condition, message)                                        \
  do {                                                                         \
    if (!(condition)) {                                                        \
      g_error("FAILED: %s - %s", __func__, message);                           \
      return FALSE;                                                            \
    } else {                                                                   \
      g_print("PASSED: %s - %s\n", __func__, message);                         \
    }                                                                          \
  } while (0)

#define RUN_TEST(test_func)                                                    \
  do {                                                                         \
    g_print("Running %s...\n", #test_func);                                    \
    if (test_func()) {                                                         \
      g_print("✓ %s completed successfully\n\n", #test_func);                  \
      tests_passed++;                                                          \
    } else {                                                                   \
      g_print("✗ %s failed\n\n", #test_func);                                  \
      tests_failed++;                                                          \
    }                                                                          \
    total_tests++;                                                             \
  } while (0)

#define PRINT_TEST_SUMMARY()                                                   \
  do {                                                                         \
    g_print("\n==================================================\n");         \
    g_print("TEST SUMMARY\n");                                                 \
    g_print("==================================================\n");           \
    g_print("Total tests: %d\n", total_tests);                                 \
    g_print("Passed: %d\n", tests_passed);                                     \
    g_print("Failed: %d\n", tests_failed);                                     \
    g_print("Success rate: %.1f%%\n",                                          \
            total_tests > 0 ? (float)tests_passed / total_tests * 100.0        \
                            : 0.0);                                            \
    g_print("==================================================\n");           \
  } while (0)

// Global test counter declarations
extern int tests_passed;
extern int tests_failed;
extern int total_tests;

#endif // TEST_FRAMEWORK_H