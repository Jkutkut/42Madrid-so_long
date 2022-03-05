# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
COMPILE			=	$(CC) $(FLAGS)
MANDATORY_EXE	=	so_long

BUFFER_S		=	42

# Binaries variables
# SRCS_MANDATORY	=	

# SRCS_BONUS		=	


# BINS_MANDATORY	=	${SRCS_MANDATORY:%.c=bin/%.o}
# BINS_BONUS		=	${SRCS_BONUS:%.c=bin/%.o}

MAN_MAIN_SRC	=	src/so_long.c
MAN_MAIN_BIN	=	${MAN_MAIN_SRC:src/%.c=bin/%.o}

# BONUS_MAIN_SRC	=	
# BONUS_MAIN_BIN	=	${BONUS_MAIN_SRC:%.c=bin/%.o}

MANDATORY		=	$(BINS_MANDATORY) $(MAN_MAIN_BIN)
# BONUS			=	$(BINS_BONUS) $(BONUS_MAIN_BIN)

MINILIBX		=	mlx_linux

NAME			=	$(MANDATORY_EXE)


# Triggers
# all: $(MANDATORY_EXE)
all: $(NAME)

# bonus: $(BONUS_EXE)

# $(MANDATORY_EXE): $(MANDATORY)
# 	$(info Compiling mandatory into $(MANDATORY_EXE))
# 	$(COMPILE) -o $(MANDATORY_EXE) $^

$(NAME): $(MANDATORY) $(MINILIBX)
	# $(CC) $(MANDATORY) -L$(MINILIBX) -l"$(MINILIBX)" -L/usr/lib -I$(MINILIBX) -lXext -lX11 -lm -lz -o $(NAME)
	$(CC) $(MANDATORY) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# $(BONUS_EXE): $(BONUS)
# 	$(info Compiling bonus into $(BONUS_EXE))
# 	$(COMPILE) -o $(BONUS_EXE) $^

# bin/%.o: %.c
# 	@echo "- Compiling $< -> $@"
# 	@mkdir -p $(dir $@)
# 	$(COMPILE) -c $< -o $@

bin/%.o: src/%.c
	mkdir -p bin
	$(COMPILE) -I/usr/include -I$(MINILIBX) -O3 -c $< -o $@


$(MINILIBX):
	make -C $(MINILIBX)

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
