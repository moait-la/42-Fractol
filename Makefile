SRCS = ./src/main.c ./src/mandelbrot.c ./src/julia.c ./src/events.c \
		./src/atod.c ./src/argsUtils.c ./src/renderUtils.c

OBJ_SRCS = ./Bonus/main.c ./Bonus/burning_ship.c ./src/events.c \
		./src/atod.c ./src/argsUtils.c ./Bonus/renderUtils.c

OBJ = ${SRCS:.c=.o}
BONUS_OBJ = ${OBJ_SRCS:.c=.o}

NAME = fractol
NAME_BONUS = fractol_bonus
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

%.o: %.c ./Includes/header.h ./libft/libft.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${SRCS} -lmlx -framework OpenGL -framework AppKit ${LIBFT} -o ${NAME}

all: ${NAME}

bonus: ${BONUS_OBJ}
	${CC} ${BONUS_OBJ} -lmlx -framework OpenGL -framework AppKit ${LIBFT} -o ${NAME_BONUS}

clean:
	${RM} ${OBJ} ${BONUS_OBJ}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: clean
