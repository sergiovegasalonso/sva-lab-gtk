#include <gtk/gtk.h>
#include "../../utils/utils.h"

void render_about_page(GtkWidget *widget, gpointer data)
{
    GtkWidget *content_area = (GtkWidget *)data;
    GtkWidget *title;
    GtkWidget *description;

    // Validate content_area
    if (!content_area || !GTK_IS_WIDGET(content_area) || !GTK_IS_BOX(content_area)) {
        g_warning("Invalid content area widget passed to render_about_page");
        return;
    }

    clear_content_area(content_area);

    title = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(title), "<span size='xx-large' weight='bold'>About Us</span>");

    description = gtk_label_new("This is a GTK4 application demonstrating navigation between different pages.\n\nBuilt with C and GTK4 toolkit for modern desktop applications.");
    gtk_label_set_wrap(GTK_LABEL(description), TRUE);

    gtk_box_append(GTK_BOX(content_area), title);
    gtk_box_append(GTK_BOX(content_area), description);

    g_print("Navigated to About\n");
}