#include <gtk/gtk.h>
#include "src/pages/about/about_page.h"
#include "src/pages/contact/contact_page.h"
#include "src/pages/home/home_page.h"

const int UNSET = -1;

GtkWidget *render_navbar(GtkWidget *content_area)
{
    GtkWidget *navbar_wrapper;
    GtkWidget *nav_button1;
    GtkWidget *nav_button2;
    GtkWidget *nav_button3;

    navbar_wrapper = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_size_request(navbar_wrapper, 200, UNSET);
    
    gtk_widget_set_margin_top(navbar_wrapper, 10);
    gtk_widget_set_margin_bottom(navbar_wrapper, 10);
    gtk_widget_set_margin_start(navbar_wrapper, 10);
    gtk_widget_set_margin_end(navbar_wrapper, 10);

    nav_button1 = gtk_button_new_with_label("Home");
    g_signal_connect(nav_button1, "clicked", G_CALLBACK(render_home_page), content_area);

    nav_button2 = gtk_button_new_with_label("About");
    g_signal_connect(nav_button2, "clicked", G_CALLBACK(render_about_page), content_area);

    nav_button3 = gtk_button_new_with_label("Contact");
    g_signal_connect(nav_button3, "clicked", G_CALLBACK(render_contact_page), content_area);

    gtk_box_append(GTK_BOX(navbar_wrapper), nav_button1);
    gtk_box_append(GTK_BOX(navbar_wrapper), nav_button2);
    gtk_box_append(GTK_BOX(navbar_wrapper), nav_button3);

    return navbar_wrapper;
}