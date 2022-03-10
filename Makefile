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

# Libraries
MINILIBX		=	mlx_linux
LIBFT			=	src/libft/libft.a

# Libraries flags
MINILIBX_FLAGS	=	-L$(MINILIBX) -lmlx_Linux -L/usr/lib -I$(MINILIBX) -lXext -lX11 -lm -lz

# Binaries variables
MAP				=	check_map_filename.c \
					endswith.c \
					load_map.c

TOOLS			=	end.c \
					freearray.c \
					ft_strextend.c

BINS_MANDATORY	=	${SRCS_MANDATORY:src/%.c=bin/%.o} ${MAP:%.c=bin/map/%.o} ${TOOLS:%.c=bin/tools/%.o}

MAN_MAIN_SRC	=	src/so_long.c
MAN_MAIN_BIN	=	${MAN_MAIN_SRC:src/%.c=bin/%.o}


MANDATORY		=	$(MAN_MAIN_BIN) $(BINS_MANDATORY) 

NAME			=	$(MANDATORY_EXE)


# Triggers
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(MANDATORY)
	@echo "\n${TITLE}Compiling${NC} ${YELLOW}mandatory${NC} into ${YELLOW}$(NAME)${NC}\c"
	@$(CC) $(MANDATORY) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)
	@echo " ${GREEN}[OK]${NC}\n"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@#$(COMPILE) -I/usr/include -I$(MINILIBX) -O3 $(LIBFT) -c $< -o $@
	@$(COMPILE) -I/usr/include -I$(MINILIBX) -O3 -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

$(MINILIBX):
	@echo "- ${TITLE}Compiling${NC} ${YELLOW}MINILIBX${NC}"
	@make -s -C $(MINILIBX)
	@echo "   - MINILIBX ${GREEN}compiled [OK]${NC}\n"

$(LIBFT):
	@make -C $(dir $(LIBFT)) BIN="../../bin/libft"

# Clean logic
.PHONY: re fclean clean $(MINILIBX) $(LIBFT)

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
