VERSION = 0.1

DESTDIR=/usr/local
MANPREFIX=$(DESTDIR)/share/man/man1

green := $(shell tput setf 2)
sgr0 := $(shell tput sgr0)

ODIR=build

GTKMMFLAGS=`pkg-config --cflags gtkmm-3.0`
GTKMMLIB=`pkg-config --libs gtkmm-3.0`

BOOSTLIBS=-lboost_regex -lboost_program_options

X11LIBS=-lX11

LIBRE_TEXTUS:=$(wildcard src/*.cpp)
LIBRE_TEXTUS+=$(wildcard src/*/*.cpp)

OBJ=$(LIBRE_TEXTUS:src/%.cpp=$(ODIR)/%.o)

CPPFLAGS=-DGETTEXT_PACKAGE=\"libretextus\" -DVERSION=\"$(VERSION)\" $(GTKMMFLAGS) -Iinclude/

LDFLAGS=$(GTKMMLIB) $(BOOSTLIBS) $(X11LIBS) -lstdc++ -lstdc++fs

CC=g++
