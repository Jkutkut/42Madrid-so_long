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
ifeq ($(OS), Darwin)
	MINILIBX	=	mlx_mac
else
	# MINILIBX	=	mlx_linux
	MINILIBX	=	mlx
endif

LIBFT			=	src/libft/libft.a

# Libraries flags
ifeq ($(OS), Darwin)
	# MINILIBX_FLAGS	=	-Lmlx_mac -lmlx_mac -framework OpenGL -framework AppKit
	MINILIBX_FLAGS	=	-lmlx_mac -framework OpenGL -framework AppKit
else
	# MINILIBX_FLAGS	=	-L$(MINILIBX) -lmlx_Linux -L/usr/lib -I$(MINILIBX) -lXext -lX11 -lm -lz
	# MINILIBX_FLAGS	=	-lmlx -lXext -lX11 -lm -lz
	MINILIBX_FLAGS		=	$(MINILIBX)/libmlx.a -lXext -lX11
endif

# Binaries variables
GAME			=	create_game.c

GAME_CONTROL	=	can_move_there.c \
					close_game.c \
					collect_coin.c \
					key_press.c \
					load_controls.c \
					move_player.c

GAME_UI			=	load_imgs.c \
					show_border.c \
					show_cell.c \
					show_img.c \
					show_level.c \
					show_player.c \
					show_wall.c

MAP				=	check_map_filename.c \
					check_update_map.c \
					count_coins.c \
					create_map.c \
					endswith.c \
					load_map.c

TOOLS			=	end.c \
					freearray.c \
					freeend.c \
					freemap.c \
					ft_strextend.c \
					print_map.c

COMMON			=	${SRCS_MANDATORY:src/%.c=bin/%.o} \
					${GAME:%.c=bin/game/%.o} \
					${GAME_CONTROL:%.c=bin/game_control/%.o} \
					${GAME_UI:%.c=bin/game_UI/%.o} \
					${MAP:%.c=bin/map/%.o} \
					${TOOLS:%.c=bin/tools/%.o}

MANDATORY_ONLY	=	game_UI/update_moves.c
BONUS_ONLY		=	${MANDATORY_ONLY:%.c=%_bonus.c}
BINS_MANDATORY	=	${COMMON} \
					${MANDATORY_ONLY:%.c=bin/%.o}

MAIN_SRC	=	src/so_long.c
MAIN_BIN	=	${MAIN_SRC:src/%.c=bin/%.o}


MANDATORY		=	$(MAIN_BIN) $(BINS_MANDATORY) 

NAME			=	$(MANDATORY_EXE)


# Triggers
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)/libmlx.a $(MANDATORY)
	@echo "\n${TITLE}Compiling${NC} ${YELLOW}mandatory${NC} into ${YELLOW}$(NAME)${NC}\c"
	@$(CC) $(MANDATORY) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)
	@#$(CC) $(MANDATORY) $(LIBFT) -o $(NAME)
	@echo " ${GREEN}[OK]${NC}\n"

bonus:
	make MANDATORY_ONLY="${BONUS_ONLY}"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@#$(COMPILE) -I/usr/include -I$(MINILIBX) -O3 -c $< -o $@
	@$(COMPILE) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

$(MINILIBX)/libmlx.a:
	@echo "- ${TITLE}Compiling${NC} ${YELLOW}MINILIBX${NC}"
	@make -C $(MINILIBX)
	@echo "   - MINILIBX ${GREEN}compiled [OK]${NC}\n"

$(LIBFT):
	@make -C $(dir $(LIBFT)) BIN="../../bin/libft"

# Clean logic
.PHONY: re fclean clean $(MINILIBX)

re: fclean all

clean:
	$(info Removing binary directory)
	@rm -rf ./bin
	make -C $(MINILIBX) clean
	make -C $(dir $(LIBFT)) fclean BIN="../../bin/libft"

fclean: clean
	$(info Removing $(MANDATORY_EXE) $(BONUS_EXE))
	@rm -f $(MANDATORY_EXE) $(BONUS_EXE)
	$(info Project now clean.)
