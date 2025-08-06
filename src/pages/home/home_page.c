#include <gtk/gtk.h>
#include "src/utils/utils.h"

static void
print_hello(GtkWidget *widget,
            gpointer data)
{
    g_print("Hello World\n");
}

void render_home_page(GtkWidget *widget, gpointer data)
{
    GtkWidget *content_area = (GtkWidget *)data;
    GtkWidget *title;
    GtkWidget *description;
    GtkWidget *button;

    if (!content_area || !GTK_IS_WIDGET(content_area) || !GTK_IS_BOX(content_area)) {
        g_warning("Invalid content area widget passed to render_home_page");
        return;
    }

    clear_content_area(content_area);

    title = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(title), "<span size='xx-large' weight='bold'>Welcome to Home</span>");

    description = gtk_label_new("This is the home page content. Here you can find an overview of the application.");
    gtk_label_set_wrap(GTK_LABEL(description), TRUE);

    button = gtk_button_new_with_label("Hello World");
    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

    gtk_box_append(GTK_BOX(content_area), title);
    gtk_box_append(GTK_BOX(content_area), description);
    gtk_box_append(GTK_BOX(content_area), button);

    g_print("Navigated to Home\n");
}