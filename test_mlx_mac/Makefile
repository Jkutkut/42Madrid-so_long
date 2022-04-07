SRCS	=	main.c
LIBFT_DIR	= libft/

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

.c.o: ${SRCS}
			${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} Makefile
			${CC} ${CFLAGS} ${MLXFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			@make -sC ${LIBFT_DIR} clean
			${RM} ${OBJS} libft.a

fclean:		clean
			@make -sC ${LIBFT_DIR} fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re