# compiler
CC = cc

# compilation flags
CFLAGS = -Wall -Werror -Wextra -g -I.

# source code
SRCS = 	main.c input_validator.c split.c split_utils.c \
	 validator_utils.c stack_builder.c linked_lst_utils.c


# objects
OBJECTS = $(SRCS:.c=.o)

# program name
NAME = push_swap

# rules
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

leakfull1:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} "5 3 2 1"

leakfull2:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} "5 3 e 1"

clean:
	@rm -rf $(OBJECTS)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Program cleaned."

re: fclean all
	@echo "Object files recreated."
	@echo "Program recreated."input_validator.c

.PHONY: all clean fclean re leakfull