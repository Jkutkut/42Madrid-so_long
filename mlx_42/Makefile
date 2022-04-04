NAME=so_long

LIB=../src/mlx/libmlx42.a

all: $(NAME)

$(NAME): $(LIB)
	@#MAC #gcc main.c MLX42/libmlx42.a -I include -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/"
	@gcc main.c $(LIB) -I include -ldl -lglfw

$(LIB):
	make -C $(dir $(LIB))
