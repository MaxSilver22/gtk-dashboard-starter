// =====================================
// MAIN MODULE
// =====================================
// Entry point for the GTK dashboard application.
// Responsible for initializing GTK, loading the custom CSS theme,
// creating the main dashboard window, and starting the main event loop.

#include <gtk/gtk.h>
#include "dashboard_window.h"

// -------------------------------
// CSS LOADING
// -------------------------------
// Loads the custom CSS file for theming (dark mode, Roboto font, sidebar/button styles, etc.)
void load_css() {
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "resources/style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}

// -------------------------------
// APPLICATION ENTRY POINT
// -------------------------------
int main(int argc, char *argv[]) {
    // Initialize GTK library
    gtk_init(&argc, &argv);
    // Load custom CSS for theming
    load_css();

    // Create the main dashboard window (contains sidebar and content area)
    GtkWidget *window = create_dashboard_window();
    // Connect the window's destroy signal to quit the GTK main loop
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show the window and all child widgets
    gtk_widget_show_all(window);
    // Start the GTK main event loop
    gtk_main();
    return 0;
} 