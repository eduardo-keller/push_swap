# compiler
CC = cc

# compilation flags
CFLAGS = -Wall -Werror -Wextra -g -I.

# source code
SRCS = 	main.c stack_builder/input_validator.c utils/split.c utils/split_utils.c utils/validator_utils.c stack_builder/stack_builder.c \
		utils/linked_lst_utils.c utils/atol.c algorithm/algo_utils.c algorithm/algorithm_call.c algorithm/movements_call.c algorithm/prep_stack_a.c \
		algorithm/prep_stack_b.c movements/movements_aggregated.c movements/movements.c 



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