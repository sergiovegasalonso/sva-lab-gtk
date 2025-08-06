#include <gtk/gtk.h>
#include "src/components/navbar/navbar.h"
#include "src/pages/home/home_page.h"
#include "src/utils/utils.h"

// global variable to hold the content area
static GtkWidget *content_area;

void load_css_file(const char *css_path) {
    GtkCssProvider *css_provider;
    GdkDisplay *display;
    
    css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(css_provider, css_path);
    
    display = gdk_display_get_default();
    gtk_style_context_add_provider_for_display(display,
                                               GTK_STYLE_PROVIDER(css_provider),
                                               GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    
    g_object_unref(css_provider);
}

void load_all_css_files() {
    load_css_file("src/main.css");
    load_css_file("src/components/navbar/navbar.css");
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *navbar;
    GtkWidget *main_box;
    GtkCssProvider *css_provider;
    GdkDisplay *display;

    load_all_css_files();

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello");
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 600);

    // create a main container box (horizontal layout)
    main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // create content area first
    content_area = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_hexpand(content_area, TRUE);
    gtk_widget_set_vexpand(content_area, TRUE);
    gtk_widget_set_margin_top(content_area, 20);
    gtk_widget_set_margin_bottom(content_area, 20);
    gtk_widget_set_margin_start(content_area, 20);
    gtk_widget_set_margin_end(content_area, 20);

    // Create navbar and add it to the main box
    navbar = render_navbar(content_area);
    gtk_box_append(GTK_BOX(main_box), navbar);

    // Add default content
    render_home_page(NULL, content_area);

    gtk_box_append(GTK_BOX(main_box), content_area);

    // Set the main box as the window's child
    gtk_window_set_child(GTK_WINDOW(window), main_box);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.lab.sva", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
