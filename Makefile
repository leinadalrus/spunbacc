<<<<<<< HEAD
CC := gcc
=======
CC := g++
>>>>>>> fad2eb094db5a6ac08384ed12207825e672a7674
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

<<<<<<< HEAD
CFLAGS := -std=c99 -g -Wall -Wextra -Wpedantic
=======
CFLAGS := -Wall -Wextra -Wpedantic
>>>>>>> fad2eb094db5a6ac08384ed12207825e672a7674
LFLAGS := -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
CPPFLAGS := $(INCL_FLAGS) -MMD -MP

$(BUILD_DIRS)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LFLAGS)

<<<<<<< HEAD
$(BUILD_DIRS)/%.c.o: %.c
=======
$(BUILD_DIRS)/%.cc.o: %.cc
>>>>>>> fad2eb094db5a6ac08384ed12207825e672a7674
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

all: $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(LFLAGS) -o $(TARGET_EXEC)

.PHONY: clean
clean:
	rm -r $(BUILD_DIRS)

-include $(DEPS)
