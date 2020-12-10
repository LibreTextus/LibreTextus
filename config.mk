VERSION = 0.1
GIT_COMMIT_ID = $(shell git log -1 --format=%cd)

DESTDIR=/usr/local
MANPREFIX=$(DESTDIR)/share/man/man1

green := $(shell tput setf 2)
sgr0 := $(shell tput sgr0)

ODIR=build

GTKMMFLAGS=`pkg-config --cflags gtkmm-3.0`
GTKMMLIB=`pkg-config --libs gtkmm-3.0`

BOOSTLIBS=-lboost_regex -lboost_program_options

X11LIBS=-lX11

LIBRE_TEXTUS:=$(shell find src -name *.cpp)

OBJ=$(LIBRE_TEXTUS:src/%.cpp=$(ODIR)/%.o)
DEPS:=$(LIBRE_TEXTUS:src/%.cpp=$(ODIR)/%.d)

CPPFLAGS=-DGETTEXT_PACKAGE=\"libretextus\" -DVERSION=\"$(VERSION)\" -DGIT_COMMIT_ID="\"$(GIT_COMMIT_ID)\"" $(GTKMMFLAGS) -Iinclude/ -Isrc/

LDFLAGS=$(GTKMMLIB) $(BOOSTLIBS) $(X11LIBS) -lstdc++ -lstdc++fs

CC=g++
