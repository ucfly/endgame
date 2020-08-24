# ======== variables ========

# -- files and dirs --
NAME = game

INC_DIR = inc
SRC_DIR = src
REC_DIR = resource


FFLAGS = -F ./resource/frameworks -framework SDL2 -rpath ./resource/frameworks \
	 -F ./resource/frameworks -framework SDL2_image -rpath ./resource/frameworks \
	 -F ./resource/frameworks -framework SDL2_ttf -rpath ./resource/frameworks \
	 -F ./resource/frameworks -framework SDL2_mixer -rpath ./resource/frameworks \

# INC_FILES = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# -- commands --
RM = rm -rdf

CC = clang
C_FLAGS =  -std=c11 -Wall -Wextra -Werror -Wpedantic 

# `sdl2-config --libs --cflags`
# LIBS = -Llib -lSDL2-2.0.0 -lSDL2_image-2.0.0
# LIBS = -lSDL2-2.0.0 -lSDL2_image-2.0.0

# ========== body =========
all: $(NAME)

$(NAME): $(SRC_FILES) $(INC_DIR) $(REC_DIR)
	@$(CC) $(C_FLAGS) $(FFLAGS) $(SRC_FILES) -I $(INC_DIR) -o $(NAME)
	
uninstall:
	@$(RM) $(NAME)

reinstall: uninstall all
