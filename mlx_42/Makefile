NAME=so_long

LIB=../src/mlx/libmlx42.a

MAIN = main.c
# MAIN = main_extended.c

all: $(NAME)

$(NAME): $(LIB)
	@gcc main.c $(LIB) -I include -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/"
	@#gcc main.c $(LIB) -I include -ldl -lglfw

$(LIB):
	make -C $(dir $(LIB))
