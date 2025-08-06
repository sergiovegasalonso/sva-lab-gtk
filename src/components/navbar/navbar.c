#include "src/pages/about/about_page.h"
#include "src/pages/contact/contact_page.h"
#include "src/pages/home/home_page.h"
#include <gtk/gtk.h>

GtkWidget *render_navbar(GtkWidget *content_area) {
  GtkWidget *navbar;
  GtkWidget *home_button;
  GtkWidget *about_button;
  GtkWidget *contact_button;

  navbar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_widget_add_css_class(navbar, "navbar");

  home_button = gtk_button_new_with_label("Home");
  g_signal_connect(home_button, "clicked", G_CALLBACK(render_home_page),
                   content_area);

  about_button = gtk_button_new_with_label("About");
  g_signal_connect(about_button, "clicked", G_CALLBACK(render_about_page),
                   content_area);

  contact_button = gtk_button_new_with_label("Contact");
  g_signal_connect(contact_button, "clicked", G_CALLBACK(render_contact_page),
                   content_area);

  gtk_box_append(GTK_BOX(navbar), home_button);
  gtk_box_append(GTK_BOX(navbar), about_button);
  gtk_box_append(GTK_BOX(navbar), contact_button);

  return navbar;
}