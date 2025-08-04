#include <gtk/gtk.h>

void clear_content_area(GtkWidget *content_area)
{
    GtkWidget *child;
    
    // Check if content_area is valid
    if (!content_area || !GTK_IS_WIDGET(content_area) || !GTK_IS_BOX(content_area)) {
        g_warning("Invalid content area widget passed to clear_content_area");
        return;
    }
    
    while ((child = gtk_widget_get_first_child(content_area)) != NULL)
    {
        gtk_box_remove(GTK_BOX(content_area), child);
    }
}