CC = gcc
CFLAGS = `pkg-config --cflags gtk4`
LIBS = `pkg-config --libs gtk4`

# Target executable
TARGET = sva-gtk

# Source files
SOURCES = main.c \
          pages/home/home_page.c \
		  pages/about/about_page.c \
		  pages/contact/contact_page.c \
          utils/utils.c

# Object files (automatically generated from source files)
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIBS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run the application
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run
