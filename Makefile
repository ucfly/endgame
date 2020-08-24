# ======== variables ========

# -- files and dirs --
NAME = game

INC_DIR = include
SRC_DIR = src
IMG_DIR = img

# INC_FILES = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# -- commands --
RM = rm -rdf

CC = clang
C_FLAGS = `sdl2-config --libs --cflags` -std=c11 -Wall -Wextra -Werror -Wpedantic 
# LIBS = -Llib -lSDL2-2.0.0 -lSDL2_image-2.0.0
LIBS = -lSDL2-2.0.0 -lSDL2_image-2.0.0

# ========== body =========
all: NAME

NAME: $(SRC_FILES)
	@$(CC) $(C_FLAGS) $(LIBS) $(SRC_FILES) -I $(INC_DIR) -o$(NAME)
	
uninstall:
	@$(RM) $(NAME)

reinstall: uninstall all
