# Utils Tests

This directory contains unit tests for the `utils.c` module of the sva-gtk library.

## Overview

The test suite covers the `clear_content_area()` function with various scenarios:

- **Valid box with children**: Tests that all child widgets are properly removed
- **Empty box**: Tests that clearing an already empty box works correctly
- **NULL parameter**: Tests that the function handles NULL input gracefully
- **Invalid widget type**: Tests that the function handles non-box widgets properly
- **Nested widgets**: Tests clearing boxes containing other boxes
- **Multiple clears**: Tests that clearing multiple times doesn't cause issues

## Requirements

- GTK4 development libraries
- GCC compiler
- pkg-config

## Building and Running Tests

### Build tests:
```bash
make
```

### Run tests:
```bash
make test
```

### Run tests with verbose output (including GTK warnings):
```bash
make test-verbose
```

### Clean build artifacts:
```bash
make clean
```

### Rebuild tests:
```bash
make rebuild
```

## Test Output

The tests will show:
- Individual test results (PASSED/FAILED)
- A summary with total tests, passed, failed, and success rate
- Expected warnings for error condition tests

Example output:
```
Starting Utils Test Suite
==================================================

Running test_clear_content_area_with_valid_box...
PASSED: test_clear_content_area_with_valid_box - Box should have children before clearing
PASSED: test_clear_content_area_with_valid_box - Box should be empty after clearing
✓ test_clear_content_area_with_valid_box completed successfully

...

==================================================
TEST SUMMARY
==================================================
Total tests: 6
Passed: 6
Failed: 0
Success rate: 100.0%
==================================================
```

## Adding New Tests

To add new tests:

1. Create a new test function following the pattern:
   ```c
   static gboolean test_your_new_test()
   {
       // Test setup
       // Test execution
       TEST_ASSERT(condition, "description");
       // Cleanup
       return TRUE;
   }
   ```

2. Add the test to the main function:
   ```c
   RUN_TEST(test_your_new_test);
   ```

## Test Macros

- `TEST_ASSERT(condition, message)`: Assert that a condition is true
- `RUN_TEST(test_func)`: Run a test function and track results
