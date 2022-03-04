# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
COMPILE			=	@$(CC) $(FLAGS)
MANDATORY_EXE	=	so_long

BUFFER_S		=	42

# Binaries variables
# SRCS_MANDATORY	=	

# SRCS_BONUS		=	


# BINS_MANDATORY	=	${SRCS_MANDATORY:%.c=bin/%.o}
# BINS_BONUS		=	${SRCS_BONUS:%.c=bin/%.o}

MAN_MAIN_SRC	=	src/so_long.c
MAN_MAIN_BIN	=	${MAN_MAIN_SRC:%.c=bin/%.o}

# BONUS_MAIN_SRC	=	
# BONUS_MAIN_BIN	=	${BONUS_MAIN_SRC:%.c=bin/%.o}

MANDATORY		=	$(BINS_MANDATORY) $(MAN_MAIN_BIN)
# BONUS			=	$(BINS_BONUS) $(BONUS_MAIN_BIN)

# Triggers
all: $(MANDATORY_EXE)

bonus: $(BONUS_EXE)

# $(MANDATORY_EXE): $(MANDATORY)
# 	$(info Compiling mandatory into $(MANDATORY_EXE))
# 	$(COMPILE) -o $(MANDATORY_EXE) $^

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# $(BONUS_EXE): $(BONUS)
# 	$(info Compiling bonus into $(BONUS_EXE))
# 	$(COMPILE) -o $(BONUS_EXE) $^

# bin/%.o: %.c
# 	@echo "- Compiling $< -> $@"
# 	@mkdir -p $(dir $@)
# 	$(COMPILE) -c $< -o $@

bin/%.o: %.c
	$(COMPILE) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# Clean logic
.PHONY: re fclean clean

re: fclean all

clean:
	$(info Removing binary directory)
	@rm -rf ./bin

fclean: clean
	$(info Removing $(MANDATORY_EXE) $(BONUS_EXE))
	@rm -f $(MANDATORY_EXE) $(BONUS_EXE)
	$(info Project now clean.)
