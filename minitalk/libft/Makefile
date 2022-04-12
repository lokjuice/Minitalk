SRCS	= ft_strlen.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

AR		= ar rcs
GCC		= gcc
RM		= rm -f

FLAGS	= -Wall -Wextra -Werror -I libft.h

%.o : %.c
		${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR}  ${NAME} $?

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
