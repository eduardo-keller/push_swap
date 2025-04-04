/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:28:54 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/01 15:13:45 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static t_list	*find_min_node(t_list *head)
{
	t_list	*min_node;
	int		min_value;

	min_node = NULL;
	min_value = INT_MAX;
	while (head)
	{
		if (head->number < min_value && head->index == 0)
		{
			min_value = head->number;
			min_node = head;
		}
		head = head->next_number;
	}
	return (min_node);
}

void	assign_index(t_list *head, int current_index)
{
	t_list	*min_node;

	if (!head)
		return ;
	min_node = find_min_node(head);
	if (min_node)
	{
		min_node->index = current_index;
		assign_index(head, current_index + 1);
	}
}

static void	stack_a_builder(int argc, char **argv, t_list **lst)
{
	t_list	*new_node;
	long	number;
	int		i;

	i = 0;
	while (i < argc)
	{
		number = ft_atol (argv[i]);
		if (number < INT_MIN || number > INT_MAX)
		{
			write (2, "Error\n", 6);
			exit (1);
		}		
		new_node = ft_lstnew((int)number, 'a');
		if (!new_node)
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		ft_lstadd_last(lst, new_node);
		i++;
	}
	assign_index(*lst, 1);
}

t_list	*stack_builder(int argc, char **argv)
{
	t_list	*lst;
	char	**final_argv;
	int		final_argc;

	lst = NULL;
	final_argv = input_argv_validator(argc, argv);
	if (!final_argv)
		return (NULL);
	final_argc = input_argc_validator(argc, argv);
	stack_a_builder(final_argc, final_argv, &lst);
	if (argc == 2)
		ft_free_split(final_argv, final_argc);
	return (lst);
}
