# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra #-fsanitize=address # -Werror -fsanitize=address
COMPILE			=	$(CC) $(FLAGS)
NAME			=	so_long

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

MINILIBX		=	src/mlx/libmlx42.a
ifeq ($(OS), Darwin)
	MINILIBX_FLAGS	=	-I include -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/"
else
	MINILIBX_FLAGS	=	-I include -ldl -lglfw
endif

# Binaries variables
GAME			=	create_game.c \
					get_player.c

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

GAME_CONTROL	=	can_move_there.c \
					collect_coin.c \
					game_tick.c \
					load_controls.c \
					move_player.c \
					tick.c


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
					${TOOLS:%=tools/%} \
					

BONUS_ONLY		=	game/count_enemy.c \
					game/create_enemy.c \
					game/get_enemies.c \
					game_control/enemy_collision.c \
					game_control/move_enemy.c \
					game_control/try_move_enemy.c \
					game_control/update_enemies.c \

SRCS			=	${COMMON:%.c=src/mandatory/%.c}
SRCS_BONUS		=	${COMMON:%.c=src/bonus/%_bonus.c} \
					${BONUS_ONLY:%.c=src/${CODE_TYPE}/bonus/%_bonus.c}

BINS			=	${SRCS:src/%.c=bin/%.o}
BINS_BONUS		=	${SRCS_BONUS:src/%.c=bin/%.o}

# Triggers
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(BINS)
	@echo "\n${TITLE}Compiling${NC} ${YELLOW}$(NAME)${NC}\c"
	@$(COMPILE) $(BINS) $(LIBFT) $(MINILIBX) $(MINILIBX_FLAGS) -o $(NAME)
	@echo " ${GREEN}[OK]${NC}\n"

bonus:
	@make BINS="${BINS_BONUS}"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

$(MINILIBX):
	@echo "- ${TITLE}Compiling${NC} ${YELLOW}MINILIBX${NC}"
	@make -s -C $(dir $(MINILIBX))
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
	@make -C $(dir $(MINILIBX)) clean
	@echo "${RED}Removing${NC} binary directory"
	@rm -rf ./bin

fclean: clean
	@echo "${RED}Removing${NC} $(NAME) $(BONUS_EXE)"
	@rm -f $(NAME)
	@echo "Project now ${GREEN}clean${NC}."
