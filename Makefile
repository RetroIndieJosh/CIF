.PHONY: all
.PHONY: install
.PHONY: clean
.PHONY: rebuild

CC=clang
LDFLAGS=-lncurses -lconfig
EXECUTABLE=cif

COPY=cp -r
MKDIR=mkdir -p
REMOVE=rm -rf

# directories
OBJDIR := obj
OUTDIR := build
RESDIR := res

vpath %.o $(OBJDIR)
vpath %.c src
vpath %.h src

# flags
CFLAGS_DEBUG :=-c -std=gnu99 -Iinclude -g -O0 -Wall -Werror -fno-inline -pedantic
CFLAGS_RELEASE :=-c -std=gnu99 -Iinclude -O2 -pedantic
CFLAGS :=$(CFLAGS_DEBUG)

# all c source files
SOURCES :=$(wildcard src/*.c)

# generate object names: change extension
OBJECT_EXT :=$(SOURCES:.c=.o)

# then strip source dir prefix
OBJECTS :=$(OBJECT_EXT:src/%=%)

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(MKDIR) $(OBJDIR)
	$(MKDIR) $(OUTDIR)
	cd $(OBJDIR); $(CC) $(OBJECTS) $(LDFLAGS) -o ../$(OUTDIR)/$@
	@echo **Copying resource files
	$(COPY) $(RESDIR)/* $(OUTDIR)

.c.o:
	@echo **Source: $<
	$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS_DEBUG) $< -o $(OBJDIR)/$@

clean:
	@echo Cleaning files...
	$(REMOVE) $(OUTDIR)
	$(REMOVE) $(OBJDIR)

rebuild:
	make clean
	make all

install:
	make all
	cp doc/man/* /usr/local/man/ -R
	mandb -q
