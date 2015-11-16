TARGET   = algo.exe

CC       = gcc -std=c99 -c
# compiling flags here
CFLAGS   = -Wall -I.

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
	@echo "Cleanup complete!"