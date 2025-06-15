CC := gcc
PROJECT_NAME := spunbacc

SRC_DIRS := ./src/

BUILD_DIRS := ./build
TARGET_EXEC = $(BUILD_DIRS)/$(PROJECT_NAME)

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.cc' \
	-or -name '*.c' -or -name '*.hpp' -or -name '*.h' -or -name '*.asm' \
		-or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIRS)/%.o)

DEPS := $(OBJS:.o=.d)

INCL_DIRS := $(shell find $(SRC_DIRS) -type d)
INCL_FLAGS := $(addprefix -I,$(INCL_DIRS))

CFLAGS := -std=c99 -g -Wall -Wextra -Wpedantic
LFLAGS := -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
CPPFLAGS := $(INCL_FLAGS) -MMD -MP

$(BUILD_DIRS)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LFLAGS)

$(BUILD_DIRS)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

all: $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(LFLAGS) -o $(TARGET_EXEC)

.PHONY: clean
clean:
	rm -r $(BUILD_DIRS)

-include $(DEPS)
