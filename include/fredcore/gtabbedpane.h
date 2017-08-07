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
 
 enum PositionPolicy
 {
 	TOP,
 	BOTTOM,
 	LEFT,
 	RIGHT
 };
 
 typedef struct _GTabbedPaneCloseButton
 {
 	GtkWidget* Button;
 	enum PositionPolicy Position;		//Top and bottom are ignored and default to right. Lazy shortcut.
 }GTabbedPaneCloseButton;
 
typedef struct _GTabbedPane
{
	//GtkNotebook...
	//Close button...
	//Other stuff?
	//enum for policy...
	
	enum PositionPolicy Positions;	//Where the panel with the tabs actually are. We have to essentially rewrite GtkNotebook so...
}GTabbedPane;
 
/* Constructor and destructor... */
GTabbedPane*	CreateGTabbedPane(GtkWidget* firstpanel, GtkWidget* button);
void*		DeleteGTabbedPane(GTabbedPaned* pane);

/* Methods... */
int		AddPanelToTabbedPane(GTabbedPane* pane, GtkWidget* panel);
GtkWidget*	RemovePanelFromTabbedPane(GTabbedPane* pane, int position);
void		RemovePanelFromTabbedPaneReference(GTabbedPane* pane, GtkWidget* widget);

void			SetGTabbedPanePositionPolicy(GTabbedPane* pane, enum PositionPolicy);
enum PositionPolicy 	GetGTabbedPanePositionPolicy(GTabbedPane* pane);

/* Constructor and destructor... */
GTabbedPaneCloseButton*	CreateGTabbedPaneCloseButton(GtkWidget* button, enum PositionPolicy position);
void			DeleteGTabbedPaneCloseButton(GTabbedPaneCloseButton* button);
