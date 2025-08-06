#include <assert.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include "src/utils/utils.h"
#include "test/_test_framework_/test_framework.h" 

gboolean test_clear_content_area_with_valid_box()
{
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    g_object_ref_sink(box);  // Take ownership of floating reference
    
    GtkWidget *label1 = gtk_label_new("Test Label 1");
    GtkWidget *label2 = gtk_label_new("Test Label 2");
    GtkWidget *button = gtk_button_new_with_label("Test Button");
    
    // Add children to the box
    gtk_box_append(GTK_BOX(box), label1);
    gtk_box_append(GTK_BOX(box), label2);
    gtk_box_append(GTK_BOX(box), button);
    
    // Verify children were added
    GtkWidget *first_child = gtk_widget_get_first_child(box);
    TEST_ASSERT(first_child != NULL, "Box should have children before clearing");
    
    // Clear the content area
    clear_content_area(box);
    
    // Verify all children were removed
    first_child = gtk_widget_get_first_child(box);
    TEST_ASSERT(first_child == NULL, "Box should be empty after clearing");
    
    // Clean up
    g_object_unref(box);
    
    return TRUE;
}

gboolean test_clear_content_area_with_empty_box()
{
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    g_object_ref_sink(box);  // Take ownership of floating reference
    
    // Verify box is empty
    GtkWidget *first_child = gtk_widget_get_first_child(box);
    TEST_ASSERT(first_child == NULL, "Box should be empty initially");
    
    // Clear the empty content area (should not crash)
    clear_content_area(box);
    
    // Verify box is still empty
    first_child = gtk_widget_get_first_child(box);
    TEST_ASSERT(first_child == NULL, "Box should still be empty after clearing");
    
    // Clean up
    g_object_unref(box);
    
    return TRUE;
}

gboolean test_clear_content_area_with_null_parameter()
{
    // This should not crash and should handle gracefully
    // The function should print a warning but not crash
    g_print("  Testing with NULL parameter (warning expected)...\n");
    clear_content_area(NULL);
    TEST_ASSERT(TRUE, "Function should handle NULL parameter gracefully");
    
    return TRUE;
}

gboolean test_clear_content_area_with_invalid_widget()
{
    // Create a non-box widget (label)
    GtkWidget *label = gtk_label_new("This is not a box");
    g_object_ref_sink(label);  // Take ownership of floating reference
    
    g_print("  Testing with non-box widget (warning expected)...\n");
    clear_content_area(label);
    TEST_ASSERT(TRUE, "Function should handle non-box widget gracefully");
    
    // Clean up
    g_object_unref(label);
    
    return TRUE;
}

gboolean test_clear_content_area_with_nested_widgets()
{
    GtkWidget *outer_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    g_object_ref_sink(outer_box);  // Take ownership of floating reference
    
    GtkWidget *inner_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget *label1 = gtk_label_new("Outer Label");
    GtkWidget *label2 = gtk_label_new("Inner Label");
    
    // Create nested structure
    gtk_box_append(GTK_BOX(inner_box), label2);
    gtk_box_append(GTK_BOX(outer_box), label1);
    gtk_box_append(GTK_BOX(outer_box), inner_box);
    
    // Verify structure
    GtkWidget *first_child = gtk_widget_get_first_child(outer_box);
    TEST_ASSERT(first_child != NULL, "Outer box should have children");
    
    // Clear the outer box
    clear_content_area(outer_box);
    
    // Verify all children were removed
    first_child = gtk_widget_get_first_child(outer_box);
    TEST_ASSERT(first_child == NULL, "Outer box should be empty after clearing");
    
    // Clean up
    g_object_unref(outer_box);
    
    return TRUE;
}

gboolean test_clear_content_area_multiple_times()
{
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    g_object_ref_sink(box);  // Take ownership of floating reference
    
    GtkWidget *label = gtk_label_new("Test Label");
    
    // Add a child
    gtk_box_append(GTK_BOX(box), label);
    
    // Clear multiple times (should not crash)
    clear_content_area(box);
    clear_content_area(box);
    clear_content_area(box);
    
    // Verify box is still empty
    GtkWidget *first_child = gtk_widget_get_first_child(box);
    TEST_ASSERT(first_child == NULL, "Box should remain empty after multiple clears");
    
    // Clean up
    g_object_unref(box);
    
    return TRUE;
}

void print_test_summary()
{
    g_print("\n==================================================\n");
    g_print("TEST SUMMARY\n");
    g_print("==================================================\n");
    g_print("Total tests: %d\n", total_tests);
    g_print("Passed: %d\n", tests_passed);
    g_print("Failed: %d\n", tests_failed);
    g_print("Success rate: %.1f%%\n", 
            total_tests > 0 ? (float)tests_passed / total_tests * 100.0 : 0.0);
    g_print("==================================================\n");
}

