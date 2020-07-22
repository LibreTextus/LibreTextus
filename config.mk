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

LIBRE_TEXTUS=framework.cpp
LIBRE_TEXTUS+=signal_handler.cpp
LIBRE_TEXTUS+=search_engine.cpp
LIBRE_TEXTUS+=window.cpp
LIBRE_TEXTUS+=source_handler.cpp
LIBRE_TEXTUS+=package_manager.cpp
LIBRE_TEXTUS+=text_view.cpp
LIBRE_TEXTUS+=path.cpp
LIBRE_TEXTUS+=notebook.cpp
LIBRE_TEXTUS+=log.cpp
LIBRE_TEXTUS+=history_button.cpp
LIBRE_TEXTUS+=exporter.cpp

OBJ=$(LIBRE_TEXTUS:%.cpp=$(ODIR)/%.o)

CPPFLAGS=-DGETTEXT_PACKAGE=\"libretextus\" -DVERSION=\"$(VERSION)\" $(GTKMMFLAGS) -Iinclude/

LDFLAGS=$(GTKMMLIB) $(BOOSTLIBS) $(X11LIBS) -lstdc++ -lstdc++fs

CC=g++
