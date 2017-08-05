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
#include <fredcore/gtextarea.h>

#include <stdlib.h>

/*
	GtkApplicationWindow (GtkMenuBar)
			GtkNotebook?? Replace???
			
 */

typedef struct
{
	GtkWidget* MenuBar;
	GtkWidget* MenuFile;
	GtkWidget* MenuHome;
	GtkWidget* MenuInsert;
	GtkWidget* MenuTranslate;
	GtkWidget* MenuHelp;
}FredTopBar;

typedef struct
{
	GtkWidget* MenuFileNew;
	GtkWidget* MenuFileOpen;
	GtkWidget* MenuFileSave;
}FileDropDown;

typedef struct
{
	GtkWidget* MenuEditCut;
	GtkWidget* MenuEditUndo;
	GtkWidget* MenuEditRedo;
}EditDropDown;

typedef struct
{
	char*       String;
	GtkWidget*  CloseButton;
}FredTabLabel;




FredTopBar* menu_bar;

GtkWidget* window;
GtkWidget* splitpane;

GtkWidget* notebook_temporary;

static void Activate(GtkApplication* application, gpointer userdata)
{
	menu_bar = (FredTopBar*)malloc(sizeof(FredTopBar));
	
	window = gtk_application_window_new(application);
	gtk_window_set_title(GTK_WINDOW(window), "FreedomEditor");
	gtk_window_set_default_size(GTK_WINDOW(window), 600, 800);	//Taller than wide.

	//splitpane = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
	//gtk_container_add(GTK_CONTAINER(window), splitpane);
	
	//menu_bar->MenuBar = 
	//gtk_application_set_menubar(G_APPLICATION(application), menu_bar->MenuBar);
	
	//gtk_application_set_menubar(application, 1);

	//notebook_temporary = gtk_notebook_new();
	//gtk_paned_add2(GTK_PANED(splitpane), notebook_temporary);

	//GtkWidget* button = gtk_button_new();
	//gtk_paned_add1(GTK_PANED(splitpane), button);
	//gtk_widget_set_can_focus(splitpane, 0);
 

	//gtk_paned_pack2(GTK_PANED(splitpane),);

	gtk_widget_show_all(window);
}

int main(int argc, char* argv[])
{
	int status;
	gtk_init(&argc, &argv);

	GtkApplication* application = gtk_application_new("com.gmail.bschneppdev.freedomeditor", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(application, "activate", G_CALLBACK(Activate), NULL);
	//g_signal_connect(application, "destroy", G_CALLBACK(gtk_main_quit), NULL);	//Do we actually need to do this? I don't think we do, but just in case..?


	
	status = g_application_run(G_APPLICATION(application), argc, argv);

	//Program's been closed.
	g_object_unref(application);
	free(menu_bar);
	return status;
}

