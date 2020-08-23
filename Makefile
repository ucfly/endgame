# A simple Makefile for compiling small SDL projects
MAINNAME = game
# set the compiler
CC := clang

# set the compiler flags
# CFLAGS := `sdl2-config --libs` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm
CFLAGS := `sdl2-config --libs --cflags` -std=c11 -Wall -Wextra -Werror -Wpedantic -Llib -lSDL2_image

SRC_DIR = src
INC_DIR = inc
# add header files here
HDRS := inc/header.h \
		#inc/get_application.h \
		#inc/hero.h \

# add source files here

SCR_FILES = $(wildcard $(SRC_DIR)/*.c)
# SRCS := src/*.c \
		# src/init_sdl.c \
		#src/render_img.c \
		#src/event.c \
		#src/get_app.c \
		#src/game_hero.c \

# generate names of object files
# OBJS := $(SRCS:.c=.o)

# name of executable
RM = rm -rf 

# default recipe
all: $(MAINNAME)

# recipe for building the final executable
$(MAINNAME): $(SCR_FILES) $(HDRS) Makefile
	@$(CC) $(CFLAGS) -o $@ $(SCR_FILES)  -I $(INC_DIR)
	@printf "\r\033[34;5m $@\t \033[32;1mcreated\033[0m\n"
# $(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
# $(OBJS): $(@:.o=.c) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	@$(RM) $(MAINNAME)
	@printf "\r\33[2KDelete \033[32;1m- temp files\033[0m\n"
uninstall: 
	@$(RM) $(MAINNAME)
	@printf "\r\033[31;6m $(MAINNAME)\t \033[32;1m$@\033[0m\n"

reinstall: uninstall all

.PHONY: all clean
