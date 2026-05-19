# 1. ISLETIM SISTEMI ALGILAMA
ifeq ($(OS),Windows_NT)
    CFLAGS = -Wall -std=c11
    LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
    EXT = .exe
    RM = del /f
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CFLAGS = -Wall -std=c11
        LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
        EXT =
        RM = rm -f
    endif
    ifeq ($(UNAME_S),Darwin)
        CFLAGS = -I/opt/homebrew/include -Wall -std=c11
        LDFLAGS = -L/opt/homebrew/lib -lraylib -framework IOKit -framework Cocoa -framework OpenGL -lm
        EXT =
        RM = rm -f
    endif
endif

# 2. DEGISKENLER
CC = gcc
COMMON = renderer.c

# 3. PROJELERIN LISTESI (Yeni bir sey yapınca buraya bosluk bırakıp eklersin)
PRODUCTS = cube starfield 

# Hepsini birden derlemek icin 'make all'
all: $(PRODUCTS)

# Her projenin derleme kuralı (Olay bu kadar basit)
cube: cube.c $(COMMON)
	$(CC) cube.c $(COMMON) -o cube$(EXT) $(CFLAGS) $(LDFLAGS)

starfield: starfield.c $(COMMON)
	$(CC) starfield.c $(COMMON) -o starfield$(EXT) $(CFLAGS) $(LDFLAGS)

# Temizlik
clean:
	$(RM) cube$(EXT) starfield$(EXT)

# Calıstırma kısayolları
run_cube: cube
	./cube$(EXT)

run_starfield: starfield
	./starfield$(EXT)