# FreedomEditor

FreedomEditor is a rewrite of the older FreedomWriter for GNU/Linux systems (on x86_64), 
in C and C++. This is a text editor intended to be able to replace my use of vim and 
gedit for developing the Feral kernel.

___

Major features to be done:

	- Freeform view
	- SHARPER language plugins (object oriented Lua-like scripting language for extensions)
	- Multi-tabbed view
	- Theming, ala Notepad++. Option to ignore system GTK+ theme.
	- Shoehorn GPU acceleration for SOMETHING.

___

Design goals:
	
	- Minimize/Eliminate use of the mouse (while still allowing it) as much as possible.
	- All commands can be done with CTRL+(FUNCTION), or with the Function keys.
	- Integrate the SHARPER language into the editor.
	- Write in GTK. Qt is a no-no.
	- Eventually port GTK (and by extension fred) to Feral Waypoint.
	- Syntax highlighting and correction
	- Overall be better than gedit.
