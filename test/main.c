#include "test/_test_framework_/test_framework.h"
#include "test/utils/utils.h"

int main(int argc, char *argv[]) {
  // Initialize GTK
  gtk_init();

  g_print("Starting Utils Test Suite\n");
  g_print("==================================================\n\n");

  // Run all tests
  RUN_TEST(test_clear_content_area_with_valid_box);
  RUN_TEST(test_clear_content_area_with_empty_box);
  RUN_TEST(test_clear_content_area_with_null_parameter);
  RUN_TEST(test_clear_content_area_with_invalid_widget);
  RUN_TEST(test_clear_content_area_with_nested_widgets);
  RUN_TEST(test_clear_content_area_multiple_times);

  // Print summary
  print_test_summary();

  // Return appropriate exit code
  return tests_failed > 0 ? 1 : 0;
}