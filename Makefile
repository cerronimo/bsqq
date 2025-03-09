CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

NAME = bsq

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

grid:

	perl tools/generate_grid.pl 15 15 3 > maps/grid1.txt
	perl tools/generate_grid.pl 20 20 7 > maps/grid2.txt
	perl tools/generate_grid.pl 100 100 10 > maps/grid3.txt
	perl tools/generate_grid.pl 27 9 3 > maps/grid4.txt

.PHONY: all clean fclean re

