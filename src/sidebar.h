#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <gtk/gtk.h>

typedef void (*SidebarCallback)(int page_index, gpointer user_data);

GtkWidget* create_sidebar();
void sidebar_set_callback(SidebarCallback cb, gpointer user_data);

#endif // SIDEBAR_H 