#FReedomEDitor Makefile
# (Consider name changes to stuff like 'Masquerade' or 'Winston' or 'Victor', the latter two being 
# references to classic literature. Or we can be cheesy and do 'gwrite').

GTK_CFLAG_INC = `pkg-config --cflags gtk+-3.0`
GTK_LIB_INC   = `pkg-config --libs gtk+-3.0`

CODENAME =-papercut	#First release... pun on how it's a text editor and menipulates written 
			#stuff!
			

# Or we can have a cheesy old cartoon reference?? Hm...
# Maybe "Cane Aint No Emacs!". Yeah, since keybinds are actually based on nano/pico.
# (Aiming to fit in Human Interface Guidelines and all that.)
# https://developer.gnome.org/hig/stable/keyboard-input.html.en
OBJECTS = fred

#CLANG IS AWESOME.
CC      = clang
CXX     = clang++
ASM     = nasm	  #Doubt we'll use it.
LD      = ld.lld
SHARPC  = bssharp #In case we embed a virtual machine for extensions and all.

## This still works on Team Blue CPUs... hopefully?
CFLAGS = -O3 -Iinclude -std=c11 -pedantic -Wall -Werror -mtune=native -march=znver1

all: main.o
	mv main.o fred$(CODENAME)

.PHONY:	clean

%.o: %.c
	$(CC) $(GTK_CFLAG_INC) $(CFLAGS) -o $@ $< $(GTK_LIB_INC)
	
clean:
	rm -rf $(OBJECTS)$(CODENAME)
	rm -rf *.o

run: all
	./$(OBJECTS)$(CODENAME)$(RELEASE_CANIDATE)
	
install: all
	sudo mv $(OBJECTS)$(CODENAME) /usr/bin
