CC := gcc

TARGET := bin
BUILDDIR := build

CFLAGS := -g -Wall

SOURCES := $(shell find $(SRCDIR) -type f -name "*.c")
OBJECTS := $(patsubst %,$(BUILDDIR)/%,$(SOURCES:.c=.o))

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	$(RM) -r $(BUILDDIR) $(TARGET)
