#include "test_framework.h"

int tests_passed = 0;
int tests_failed = 0;
int total_tests = 0;

void run_test_impl(TestFunc fn, const char *name) {
  g_print("Running %s...\n", name);

  if (fn()) {
    g_print("✓ %s completed successfully\n\n", name);
    tests_passed++;
  } else {
    g_print("✗ %s failed\n\n", name);
    tests_failed++;
  }

  total_tests++;
}