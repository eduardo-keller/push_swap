#include "push.h"

char **input_validator(int argc, char **argv)
{
	char 	**final_input;
	int	final_argc;

	final_input = input_str_validator(argc, argv);
	if (!final_input)
		return (0);
	final_argc = argc_validator(argc, argv);
}

char	**input_str_validator(int argc, char **argv)
{
	char	**final_input;

	if (argc == 2)
	{
		final_input = split(argv);
	}
	else
		final_input = argv;
	return (final_input);
}

int	argc_validator(int argc, char **argv)
{
	int	final_argc;
	
	if (argc == 2)
		final_argc = ft_count_items(argv[1], ' ');
	else
		final_argc = argc;
	return (final_argc);
}

