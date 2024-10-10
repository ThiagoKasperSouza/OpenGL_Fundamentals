all: main

PROJECT_NAME = Opengl_fundamentals
CC=gcc

PKG_CFLAGS = $(shell pkg-config --cflags ) -lm
PKG_LIBS = $(shell pkg-config --libs) -lm -lGL -lGLU -lglut
$(PROJECT_NAME): main

main: main.c
	$(CC) -I$(LIB_DIR) $(PKG_CFLAGS) -o $@ $< $(PKG_LIBS)
main-debug: main.c
	$(CC) -I$(LIB_DIR) $(PKG_CFLAGS) -o $@ $< $(PKG_LIBS)

clean:
	rm -rf main main-debug


