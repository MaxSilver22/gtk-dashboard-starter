// =====================================
// DASHBOARD WINDOW MODULE
// =====================================
// This module constructs the main dashboard window, which contains
// the fixed sidebar (navigation) and the scrollable content area (pages).
// It wires up the sidebar to control which page is shown in the content area.

#include <gtk/gtk.h>
#include "sidebar.h"
#include "content_area.h"

// -------------------------------
// SIDEBAR CALLBACK HANDLER
// -------------------------------
// This function is called when a sidebar button is clicked.
// It switches the content area to the corresponding page.
static void on_sidebar_page_selected(int page_index, gpointer user_data) {
    content_area_show_page(page_index);
}

// -------------------------------
// DASHBOARD WINDOW CONSTRUCTION
// -------------------------------
// Creates the main dashboard window, including the sidebar and content area.
// Returns a GtkWidget* representing the top-level window.
GtkWidget* create_dashboard_window() {
    // Create the main application window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Dashboard");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 700);

    // Create a horizontal box to hold the sidebar and content area
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(window), hbox);

    // Create and add the sidebar (navigation)
    GtkWidget *sidebar = create_sidebar();
    gtk_box_pack_start(GTK_BOX(hbox), sidebar, FALSE, FALSE, 0);

    // Create and add the content area (pages)
    GtkWidget *content = create_content_area();
    gtk_box_pack_start(GTK_BOX(hbox), content, TRUE, TRUE, 0);

    // Wire up the sidebar to control the content area
    sidebar_set_callback(on_sidebar_page_selected, NULL);
    // Show the first page by default
    content_area_show_page(0);

    // Return the fully constructed window
    return window;
} 