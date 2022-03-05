# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra # -Werror -fsanitize=address
COMPILE			=	$(CC) $(FLAGS)
MANDATORY_EXE	=	so_long

# Libraries
MINILIBX		=	mlx_linux
LIBFT			=	"src/libft"

# Libraries flags
LIBFT_FLAGS		=	-L$(LIBFT) -I$(LIBFT)
MINILIBX_FLAGS	=	-L$(MINILIBX) -lmlx_Linux -L/usr/lib -I$(MINILIBX) -lXext -lX11 -lm -lz

# Binaries variables
SRCS_MANDATORY	=	src/end.c

BINS_MANDATORY	=	${SRCS_MANDATORY:src/%.c=bin/%.o}

MAN_MAIN_SRC	=	src/so_long.c
MAN_MAIN_BIN	=	${MAN_MAIN_SRC:src/%.c=bin/%.o}


MANDATORY		=	$(MAN_MAIN_BIN) $(BINS_MANDATORY) 

NAME			=	$(MANDATORY_EXE)


# Triggers
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(MANDATORY)
	$(CC) $(MANDATORY) $(LIBFT_FLAGS) $(MINILIBX_FLAGS) -o $(NAME)

bin/%.o: src/%.c
	mkdir -p bin
	$(COMPILE) -I/usr/include -I$(MINILIBX) -O3 -I$(LIBFT) -c $< -o $@

$(MINILIBX):
	@make -C $(MINILIBX)

$(LIBFT):
	@make -C $(LIBFT)

# Clean logic
.PHONY: re fclean clean $(MINILIBX) $(LIBFT)

re: fclean all

clean:
	$(info Removing binary directory)
	@rm -rf ./bin
	make -C $(MINILIBX) clean
	make -C $(LIBFT) fclean

fclean: clean
	$(info Removing $(MANDATORY_EXE) $(BONUS_EXE))
	@rm -f $(MANDATORY_EXE) $(BONUS_EXE)
	$(info Project now clean.)
