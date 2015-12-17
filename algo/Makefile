ifeq ($(OS),Windows_NT)
	# cygwin, visual studio
	TARGET = algo.exe
else
	# Linux
	TARGET = algo.out
endif

CC       = gcc -std=c99 -c
# compiling flags here
CFLAGS   = -Wall -Wno-unused-function -I.

LINKER   = gcc -o
# linking flags here
LFLAGS   = -Wall

SOURCES  := $(wildcard *.c)
INCLUDES := $(wildcard *.h)
OBJECTS  := $(SOURCES:.c=*.o)
rm       = rm -f

$(TARGET): obj
	@$(LINKER) $(TARGET) $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

obj: $(SOURCES) $(INCLUDES)
	@$(CC) $(CFLAGS) $(SOURCES)
	@echo "Compilation complete!"

.PHONY: clean

clean:
	@$(rm) $(TARGET) $(OBJECTS)
	@$(rm) r.txt
	@echo "Cleanup complete!"

