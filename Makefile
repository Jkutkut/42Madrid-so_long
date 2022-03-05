# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra # -Werror
COMPILE			=	$(CC) $(FLAGS)
MANDATORY_EXE	=	so_long

# Binaries variables
SRCS_MANDATORY	=	src/end.c

BINS_MANDATORY	=	${SRCS_MANDATORY:src/%.c=bin/%.o}

MAN_MAIN_SRC	=	src/so_long.c
MAN_MAIN_BIN	=	${MAN_MAIN_SRC:src/%.c=bin/%.o}


MANDATORY		=	$(BINS_MANDATORY) $(MAN_MAIN_BIN)

MINILIBX		=	mlx_linux

NAME			=	$(MANDATORY_EXE)


# Triggers
all: $(NAME)

$(NAME): $(MANDATORY) $(MINILIBX)
	$(CC) $(MANDATORY) -L$(MINILIBX) -lmlx_Linux -L/usr/lib -I$(MINILIBX) -lXext -lX11 -lm -lz -o $(NAME)

bin/%.o: src/%.c
	mkdir -p bin
	$(COMPILE) -I/usr/include -I$(MINILIBX) -O3 -c $< -o $@

$(MINILIBX):
	@make -C $(MINILIBX)

# Clean logic
.PHONY: re fclean clean $(MINILIBX)

re: fclean all

clean:
	$(info Removing binary directory)
	@rm -rf ./bin
	make -C $(MINILIBX) clean

fclean: clean
	$(info Removing $(MANDATORY_EXE) $(BONUS_EXE))
	@rm -f $(MANDATORY_EXE) $(BONUS_EXE)
	$(info Project now clean.)
