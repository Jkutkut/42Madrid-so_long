# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra #-fsanitize=address # -Werror -fsanitize=address
COMPILE			=	$(CC) $(FLAGS)
MANDATORY_EXE	=	so_long

# Colors:
NC				=	\033[0m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
LRED			=	\033[1;31m
LGREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
LBLUE			=	\033[1;34m
TITLE			=	\033[38;5;33m

OS			=	$(shell uname -s)

# Libraries
LIBFT			=	src/libft/libft.a

ifeq ($(OS), Darwin)
	CODE_TYPE		=	mac
	MINILIBX		=	mlx_mac
	MINILIBX_FLAGS	=	-Lmlx_mac -lmlx_mac -framework OpenGL -framework AppKit
	DOT_O_FLAGS		=	-Imlx_mac
else
	CODE_TYPE		=	linux
	MINILIBX		=	src/mlx
	MINILIBX_FLAGS	=	$(MINILIBX)/libmlx.a -lXext -lX11
endif

# Binaries variables
GAME			=	create_game.c \
					get_player.c

GAME_CONTROL	=	can_move_there.c \
					close_game.c \
					collect_coin.c \
					key_press.c \
					load_controls.c \
					move_player.c

GAME_UI			=	load_imgs.c \
					show_border.c \
					show_cell.c \
					show_enemies.c \
					show_entity.c \
					show_exits.c \
					show_img.c \
					show_level.c \
					show_player.c \
					show_wall.c \
					update_moves.c

MAP				=	check_map_filename.c \
					check_unique_player.c \
					check_update_map.c \
					check_valid_line.c \
					count_coins.c \
					create_map.c \
					endswith.c \
					load_map.c \
					map_contains.c

TOOLS			=	end.c \
					freearray.c \
					freeend.c \
					freemap.c \
					ft_strextend.c \
					print_map.c

COMMON			=	so_long.c \
					${GAME:%=game/%} \
					${GAME_CONTROL:%=game_control/%} \
					${GAME_UI:%=game_UI/%} \
					${MAP:%=map/%} \
					${TOOLS:%=tools/%}

SRCS			=	${COMMON:%.c=src/${CODE_TYPE}/mandatory/%.c}

BINS			=	${SRCS:src/%.c=bin/%.o}

NAME			=	$(MANDATORY_EXE)

# Triggers
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)/libmlx.a $(BINS)
	@echo "\n${TITLE}Compiling${NC} ${YELLOW}$(NAME)${NC}\c"
	@$(COMPILE) $(BINS) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)
	@echo " ${GREEN}[OK]${NC}\n"

bonus:
	@#make BINS_MANDATORY="${BINS_BONUS}" MAIN_SRC="${MAIN_SRC:src/%.c=bin/%_bonus.o}" #DEFINES='${DEFINES} -D ALL_ELEMENTS="10CEPF"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

$(MINILIBX)/libmlx.a:
	@echo "- ${TITLE}Compiling${NC} ${YELLOW}MINILIBX${NC}"
	@make -s -C $(MINILIBX)
	@echo "   - MINILIBX ${GREEN}compiled [OK]${NC}\n"

$(LIBFT):
	@make -C $(dir $(LIBFT)) BIN="../../bin/libft"

# Clean logic
.PHONY: re fclean clean $(MINILIBX)

re: fclean all

clean:
	@echo "${RED}Removing${NC} ${YELLOW}Libft${NC} binaries"
	@make -C $(dir $(LIBFT)) fclean BIN="../../bin/libft"
	@echo "${RED}Removing${NC} ${YELLOW}MINILIBX${NC} binaries"
	@make -C $(MINILIBX) clean
	@echo "${RED}Removing${NC} binary directory"
	@rm -rf ./bin

fclean: clean
	@echo "${RED}Removing${NC} $(MANDATORY_EXE) $(BONUS_EXE)"
	@rm -f $(MANDATORY_EXE) $(BONUS_EXE)
	@echo "Project now ${GREEN}clean${NC}."
