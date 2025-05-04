#include <gtk/gtk.h>

// Number of sidebar navigation buttons
#define NUM_BUTTONS 5

// Pointer to the currently active (highlighted) sidebar button
static GtkWidget *active_button = NULL;

// Callback type for notifying when a sidebar button is clicked
// page_index: the index of the button (0-based)
// user_data: user-supplied pointer for context
typedef void (*SidebarCallback)(int page_index, gpointer user_data);

// Static variables to store the callback and its user data
static SidebarCallback sidebar_callback = NULL;
static gpointer sidebar_callback_data = NULL;

// This function is called whenever a sidebar button is clicked
// It updates the active button highlight and notifies the main window/content area
static void on_sidebar_button_clicked(GtkButton *button, gpointer user_data) {
    int idx = GPOINTER_TO_INT(user_data); // Get the button index
    // Remove the 'active' CSS class from the previously active button
    if (active_button) {
        GtkStyleContext *ctx = gtk_widget_get_style_context(active_button);
        gtk_style_context_remove_class(ctx, "active");
    }
    // Add the 'active' CSS class to the newly clicked button
    GtkStyleContext *ctx = gtk_widget_get_style_context(GTK_WIDGET(button));
    gtk_style_context_add_class(ctx, "active");
    active_button = GTK_WIDGET(button);
    // Notify the registered callback (if any) to switch the content page
    if (sidebar_callback)
        sidebar_callback(idx, sidebar_callback_data);
}

// Allows the main window to register a callback for sidebar navigation events
void sidebar_set_callback(SidebarCallback cb, gpointer user_data) {
    sidebar_callback = cb;
    sidebar_callback_data = user_data;
}

// Creates the sidebar widget, including the logo and navigation buttons
GtkWidget* create_sidebar() {
    // Create a vertical box to hold the logo and buttons
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    // Set a fixed width for the sidebar (matches CSS)
    gtk_widget_set_size_request(vbox, 120, -1); // Reduced width
    gtk_widget_set_vexpand(vbox, TRUE); // Expand vertically to fill sidebar
    gtk_style_context_add_class(gtk_widget_get_style_context(vbox), "sidebar"); // For CSS styling

    // --- Sidebar Logo ---
    // Add a logo image at the top of the sidebar
    GtkWidget *logo = gtk_image_new_from_file("resources/logo/logo.png");
    gtk_widget_set_margin_top(logo, 12);    // Margin above logo
    gtk_widget_set_margin_bottom(logo, 12); // Margin below logo
    gtk_widget_set_halign(logo, GTK_ALIGN_CENTER); // Center the logo horizontally
    gtk_box_pack_start(GTK_BOX(vbox), logo, FALSE, FALSE, 0);

    // --- Sidebar Navigation Buttons ---
    // Create NUM_BUTTONS navigation buttons
    for (int i = 0; i < NUM_BUTTONS; ++i) {
        char label[32];
        snprintf(label, sizeof(label), "Button%d", i+1); // Button label (Button1, Button2, ...)
        GtkWidget *btn = gtk_button_new_with_label(label);
        gtk_box_pack_start(GTK_BOX(vbox), btn, FALSE, FALSE, 0); // Add button to sidebar
        // Remove all margins for a tight, minimal look
        gtk_widget_set_margin_top(btn, 0);
        gtk_widget_set_margin_bottom(btn, 0);
        gtk_widget_set_margin_start(btn, 0);
        gtk_widget_set_margin_end(btn, 0);
        // Add the sidebar-button CSS class for styling
        gtk_style_context_add_class(gtk_widget_get_style_context(btn), "sidebar-button");
        // Connect the click event to our handler, passing the button index
        g_signal_connect(btn, "clicked", G_CALLBACK(on_sidebar_button_clicked), GINT_TO_POINTER(i));
        // Set the first button as active by default
        if (i == 0) {
            gtk_style_context_add_class(gtk_widget_get_style_context(btn), "active");
            active_button = btn;
        }
    }
    // Return the fully constructed sidebar widget
    return vbox;
} 