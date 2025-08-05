#######
# app #
#######
CC = gcc
CFLAGS = `pkg-config --cflags gtk4`
LIBS = `pkg-config --libs gtk4`

# target executable
TARGET = sva-gtk

# source files
SOURCES = src/main.c \
          src/pages/home/home_page.c \
		  src/pages/about/about_page.c \
		  src/pages/contact/contact_page.c \
          src/utils/utils.c

# object files automatically generated from source files
OBJECTS = $(SOURCES:.c=.o)

# default target
all: $(TARGET)

# build the executable (alias for build)
build: $(TARGET)

# build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIBS)

# compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# rebuild everything
rebuild: clean build

# run the application
run: $(TARGET)
	./$(TARGET)

.PHONY: all build clean rebuild run

#########
# test  #
#########
CC_TEST = gcc
CFLAGS_TEST = `pkg-config --cflags gtk4` -Wall -Wextra -g
LIBS_TEST = `pkg-config --libs gtk4`

# target executable
TARGET_TEST = sva-gtk-test

# source files
SOURCES_TEST = test/utils/utils.c src/utils/utils.c

# object files automatically generated from source files
OBJECTS_TEST = $(SOURCES_TEST:.c=.o)

# default target
all-test: $(TARGET_TEST)

# build the test executable (alias for build-test)
build-test: $(TARGET_TEST)

# build the executable
$(TARGET_TEST): $(OBJECTS_TEST)
	$(CC_TEST) $(OBJECTS_TEST) -o $(TARGET_TEST) $(LIBS_TEST)

# compile test source files to object files (separate rule to avoid conflicts)
test/%.o: test/%.c
	$(CC_TEST) $(CFLAGS_TEST) -c $< -o $@

# run tests
test: $(TARGET_TEST)
	./$(TARGET_TEST)

# run tests with verbose output
test-verbose: $(TARGET_TEST)
	G_MESSAGES_DEBUG=all ./$(TARGET_TEST)

# clean artifacts
clean-test:
	rm -f $(OBJECTS_TEST) $(TARGET_TEST)

# rebuild everything
rebuild-test: clean-test build-test

.PHONY: all-test build-test test test-verbose clean-test rebuild-test