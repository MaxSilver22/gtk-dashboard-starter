// =====================================
// CONTENT AREA MODULE
// =====================================
// This module implements the scrollable content area of the dashboard.
// It uses a GtkStack to hold multiple pages, each with a title and sample content.
// The visible page is controlled by the sidebar navigation.

#include <gtk/gtk.h>
#include <string.h>

// -------------------------------
// CONFIGURATION & STATE
// -------------------------------
#define NUM_PAGES 5 // Number of content pages

// Static pointer to the GtkStack used for page switching
static GtkWidget *stack = NULL;

// Sample lorem ipsum text for demonstration
static const char *lorem1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";
static const char *lorem2 = "Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.";

// -------------------------------
// CONTENT AREA CONSTRUCTION
// -------------------------------
// Creates the scrollable content area with multiple pages.
// Each page has a title and two paragraphs of sample text.
// Returns a GtkWidget* representing the content area.
GtkWidget* create_content_area() {
    // Create a scrolled window to allow vertical scrolling of content
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_style_context_add_class(gtk_widget_get_style_context(scrolled), "content-area");

    // Create a GtkStack to hold the different pages
    stack = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_NONE); // No animation

    // Create NUM_PAGES pages, each with a title and two paragraphs
    for (int i = 0; i < NUM_PAGES; ++i) {
        char title[32];
        snprintf(title, sizeof(title), "Page%d", i+1);
        // Create a vertical box for the page content
        GtkWidget *page_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 16);
        // Set equal margin on all sides for consistent padding
        gtk_widget_set_margin_top(page_box, 40);
        gtk_widget_set_margin_bottom(page_box, 40);
        gtk_widget_set_margin_start(page_box, 40);
        gtk_widget_set_margin_end(page_box, 40);

        // Add a large, bold label as the page title
        GtkWidget *h1 = gtk_label_new(title);
        gtk_widget_set_halign(h1, GTK_ALIGN_START);
        gtk_widget_set_valign(h1, GTK_ALIGN_START);
        gtk_style_context_add_class(gtk_widget_get_style_context(h1), "h1");
        gtk_box_pack_start(GTK_BOX(page_box), h1, FALSE, FALSE, 0);

        // Add two paragraphs of sample text
        GtkWidget *p1 = gtk_label_new(lorem1);
        gtk_label_set_line_wrap(GTK_LABEL(p1), TRUE);
        gtk_widget_set_halign(p1, GTK_ALIGN_START);
        gtk_box_pack_start(GTK_BOX(page_box), p1, FALSE, FALSE, 0);

        GtkWidget *p2 = gtk_label_new(lorem2);
        gtk_label_set_line_wrap(GTK_LABEL(p2), TRUE);
        gtk_widget_set_halign(p2, GTK_ALIGN_START);
        gtk_box_pack_start(GTK_BOX(page_box), p2, FALSE, FALSE, 0);

        // Add the page to the stack with a unique name
        gtk_stack_add_titled(GTK_STACK(stack), page_box, title, title);
    }

    // Add the stack to the scrolled window
    gtk_container_add(GTK_CONTAINER(scrolled), stack);
    return scrolled;
}

// -------------------------------
// PAGE SWITCHING
// -------------------------------
// Switches the visible page in the content area by index (0-based)
void content_area_show_page(int page_index) {
    char title[32];
    snprintf(title, sizeof(title), "Page%d", page_index+1);
    if (stack)
        gtk_stack_set_visible_child_name(GTK_STACK(stack), title);
} 