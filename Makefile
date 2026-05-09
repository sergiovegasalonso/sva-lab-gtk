# ========== CONFIG ==========
CC			:= gcc
PKG_CONFIG  := pkg-config
GTK_CFLAGS  := $(shell $(PKG_CONFIG) --cflags gtk4)
GTK_LIBS	:= $(shell $(PKG_CONFIG) --libs gtk4)
INCLUDES	:= -I.

CFLAGS		:= $(GTK_CFLAGS) $(INCLUDES)
LDFLAGS		:= $(GTK_LIBS)

# ========== APP BUILD ==========
APP_NAME	:= sva-gtk
APP_SRC		:= src/main.c \
			   src/pages/home/home_page.c \
			   src/pages/about/about_page.c \
			   src/pages/contact/contact_page.c \
			   src/utils/utils.c \
			   src/components/navbar/navbar.c
APP_OBJS	:= $(APP_SRC:.c=.o)

# ========== TEST BUILD ==========
TEST_NAME   := sva-gtk-test
TEST_SRC	:= test/main.c \
			   test/_test_framework_/test_framework.c \
			   test/utils/utils.c \
			   src/utils/utils.c
TEST_OBJS   := $(TEST_SRC:.c=.o)

# ========== DEFAULT TARGET ==========
.PHONY: all
all: build

# ========== BUILD RULES ==========
.PHONY: build
build: $(APP_NAME)

$(APP_NAME): $(APP_OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

.PHONY: build-test
build-test: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

# ========== COMPILE RULE ==========
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ========== RUN ==========
.PHONY: run
run: $(APP_NAME)
	./$(APP_NAME)

.PHONY: test
test: $(TEST_NAME)
	G_MESSAGES_DEBUG=all ./$(TEST_NAME)

# ========== CLEAN ==========
.PHONY: clean clean-test clean-all
clean:
	rm -f $(APP_OBJS) $(APP_NAME)

clean-test:
	rm -f $(TEST_OBJS) $(TEST_NAME)

clean-all: clean clean-test

# ========== REBUILD ==========
.PHONY: rebuild rebuild-test rebuild-all
rebuild: clean build
rebuild-test: clean-test build-test
rebuild-all: clean-all build build-test
