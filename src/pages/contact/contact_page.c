#include "src/utils/utils.h"
#include <gtk/gtk.h>

void render_contact_page(GtkWidget *widget, gpointer data) {
  GtkWidget *content_area = (GtkWidget *)data;
  GtkWidget *title;
  GtkWidget *description;
  GtkWidget *email_label;

  if (!content_area || !GTK_IS_WIDGET(content_area) ||
      !GTK_IS_BOX(content_area)) {
    g_warning("Invalid content area widget passed to render_contact_page");
    return;
  }

  clear_content_area(content_area);

  title = gtk_label_new(NULL);
  gtk_label_set_markup(
      GTK_LABEL(title),
      "<span size='xx-large' weight='bold'>Contact Information</span>");

  description =
      gtk_label_new("Get in touch with us using the information below:");
  gtk_label_set_wrap(GTK_LABEL(description), TRUE);

  gtk_box_append(GTK_BOX(content_area), title);
  gtk_box_append(GTK_BOX(content_area), description);

  g_print("Navigated to Contact\n");
}