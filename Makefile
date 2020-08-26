# ======== variables ========

# -- files and dirs --
NAME = endgame

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
	@printf "\r\33[2K$@\t \033[32;1mcreated\033[0m\n"
	
uninstall:
	@$(RM) $(NAME)
	@printf "\r\33[2K$(NAME)\t \033[32;1mdeleted\033[0m\n"

reinstall: uninstall all
