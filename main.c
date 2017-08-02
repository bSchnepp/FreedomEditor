/*
Copyright (c) 2017 Brian Schnepp

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include <gtk/gtk.h>

static void Activate(GtkApplication* application, gpointer userdata)
{
	GtkWidget* window;
	
	window = gtk_application_window_new(application);
	gtk_window_set_title(GTK_WINDOW(window), "FreedomEditor");
	gtk_window_set_default_size(GTK_WINDOW(window), 600, 800);	//Taller than wide.
	gtk_widget_show_all(window);
}

int main(int argc, char* argv[])
{
	int status;

	GtkApplication* application = gtk_application_new("com.gmail.bschneppdev.freedomeditor", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(application, "activate", G_CALLBACK(Activate), NULL);
	status = g_application_run(G_APPLICATION(application), argc, argv);

	//Program's been closed.
	g_object_unref(application);
	return status;
}

