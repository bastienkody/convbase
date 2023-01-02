SRCS =	ft_convert_base.c \
		ft_convert_base2.c \
		ft_printers.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = convbase

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		rm -rf *.o

fclean:	clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
