NAME = bsq

SRC = fill_listarray.c get_dimensions.c list_functions.c find_square.c input.c square_index_check.c main.c\
	  draw_square.c

OBJ = fill_listarray.o get_dimensions.o list_functions.o find_square.o input.o square_index_check.o main.o\
	  draw_square.o

all: $(NAME)

$(NAME): $(SRC)
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
