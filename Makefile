#FReedomEDitor Makefile
# (Consider name changes to stuff like 'Masquerade' or 'Winston' or 'Victor', the latter two being 
# references to classic literature. Or we can be cheesy and do 'gwrite)'

GTK_CFLAG_INC = `pkg-config --cflags gtk+-3.0`
GTK_LIB_INC   = `pkg-config --libs gtk+-3.0`

CODENAME = -papercut	#First release... pun on how it's a text editor and menipulates written 
			#stuff!

OBJECTS = fred

#CLANG IS AWESOME.
CC      = clang
CXX     = clang++
ASM     = nasm	 #Doubt we'll use it.
LD      = ld.lld
SHARPC  = bssharp #In case we embed a virtual machine for extensions and all.

CFLAGS = -O3 -Iinclude

all: main.o
	mv main.o fred

%.o: %.c
	$(CC) $(GTK_CFLAG_INC) -o $@ $< $(GTK_LIB_INC)
	
