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

typedef struct _GTextArea
{
	GtkApplication* parent;	//TODO...
	
	/* Things we care mostly about... */
	GtkWidget* scroll_window;


	/* Everything we make is a child of the scroll window... */
	GtkWidget* text_view;
	
	/* Functions for the class...*/
	void (*Undo)(struct _GTextArea* area);
	void (*Redo)(struct _GTextArea* area);
	void (*Cache)(struct _GTextArea* area, char* content);
		
	/* In case we expand on the functions of the class... */
	void (*reserved0)(void);
	void (*reserved1)(void);
	void (*reserved2)(void);
	void (*reserved3)(void);
	void (*reserved4)(void);
	void (*reserved5)(void);
	
	/* Data members... */
	char* local_cache;
}GTextArea;

GTextArea* CreateGTextArea(GtkWidget* parent);
void       DeleteGTextArea(GTextArea* area);
