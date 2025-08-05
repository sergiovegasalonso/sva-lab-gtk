#include <gtk/gtk.h>

#ifndef UTILS_H
#define UTILS_H

gboolean test_clear_content_area_with_valid_box();
gboolean test_clear_content_area_with_empty_box();
gboolean test_clear_content_area_with_null_parameter();
gboolean test_clear_content_area_with_invalid_widget();
gboolean test_clear_content_area_with_nested_widgets();
gboolean test_clear_content_area_multiple_times();
void print_test_summary();

#endif // UTILS_H