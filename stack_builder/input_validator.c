/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:28:35 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/01 15:30:02 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

char	**input_argv_validator(int argc, char **argv)
{
	char	**final_input;

	if (argc == 2)
	{
		final_input = ft_split(argv[1], ' ');
	}
	else
		final_input = argv + 1;
	return (final_input);
}

int	input_argc_validator(int argc, char **argv)
{
	int	final_argc;

	if (argc == 2)
		final_argc = count_words(argv[1], ' ');
	else
		final_argc = argc - 1;
	return (final_argc);
}

static void	need_free(int should_free, char **argv, int argc)
{
	if (should_free == 1)
		ft_free_split(argv, argc);
}

int	input_validator(int argc, char **argv)
{
	char	**final_argv;
	int		final_argc;
	int		should_free;

	should_free = 0;
	final_argv = input_argv_validator(argc, argv);
	if (argc == 2)
		should_free = 1;
	if (!final_argv)
		return (0);
	final_argc = input_argc_validator(argc, argv);
	if (input_item_validator(final_argc, final_argv) == 0)
	{
		need_free(should_free, final_argv, final_argc);
		return (0);
	}	
	need_free(should_free, final_argv, final_argc);
	return (1);
}

int	input_duplicates_validator(t_list **lst)
{
	t_list	*current_node;
	t_list	*iteration_node;
	int		current_number;

	if (!*lst || !lst)
		return (0);
	current_node = *lst;
	while (current_node)
	{
		iteration_node = current_node->next_number;
		current_number = current_node->number;
		while (iteration_node)
		{
			if (current_number == iteration_node->number)
				return (0);
			iteration_node = iteration_node->next_number;
		}
		current_node = current_node->next_number;
	}
	return (1);
}
