NAME =	libftprintf.a

CFLAGS	=	-Wall -Werror -Wextra -c

CC	=	gcc

LIB = ar -rc

RAN = ranlib

SRC = main.c		\
	ft_printf.c \
	  ft_printf_utils.c \
	  ft_convert.c \
	  ft_convert2.c \
	  ft_itoa.c \
	  ft_check.c \
	  ft_write_integer.c \
	  ft_write_nn_integer.c \
	  ft_write_pn_integer.c \
	  ft_write_width.c \
	  ft_write_string.c

OBJ = ${SRC:.c=.o}

RM = rm -f

%.o : %.c
	${CC} ${CFLAGS} $<

$(NAME) : $(OBJ)
	${LIB} ${NAME} ${OBJ}
	${RAN} ${NAME}

all: $(NAME)

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
