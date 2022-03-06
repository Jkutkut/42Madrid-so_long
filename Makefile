# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra # -Werror -fsanitize=address
COMPILE			=	$(CC) $(FLAGS)
MANDATORY_EXE	=	so_long

# Libraries
MINILIBX		=	mlx_linux
LIBFT			=	src/libft/libft.a

# Libraries flags
MINILIBX_FLAGS	=	-L$(MINILIBX) -lmlx_Linux -L/usr/lib -I$(MINILIBX) -lXext -lX11 -lm -lz

# Binaries variables
SRCS_MANDATORY	=	src/end.c \
					src/valid_map.c \
					src/get_next_line/get_next_line.c

BINS_MANDATORY	=	${SRCS_MANDATORY:src/%.c=bin/%.o}

MAN_MAIN_SRC	=	src/so_long.c
MAN_MAIN_BIN	=	${MAN_MAIN_SRC:src/%.c=bin/%.o}


MANDATORY		=	$(MAN_MAIN_BIN) $(BINS_MANDATORY) 

NAME			=	$(MANDATORY_EXE)


# Triggers
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(MANDATORY)
	$(CC) $(MANDATORY) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)

bin/%.o: src/%.c
	mkdir -p $(dir $@)
	$(COMPILE) -I/usr/include -I$(MINILIBX) -O3 $(LIBFT) -c $< -o $@

$(MINILIBX):
	@make -C $(MINILIBX)

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
