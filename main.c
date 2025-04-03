/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:28:52 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/03 12:07:17 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char **argv)
{
	int		validator;
	int		val_dup;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc == 1)
		return (0);
	validator = input_validator(argc, argv);
	if (validator == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	lst_a = stack_builder(argc, argv);
	val_dup = input_duplicates_validator(&lst_a);
	if (val_dup == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	final_algorithm(&lst_a, &lst_b);
	free_lst(lst_a, lst_b);
	return (0);
}

void	free_lst(t_list *lst1, t_list *lst2)
{
	t_list	*temp1;
	t_list	*temp2;

	while (lst1)
	{
		temp1 = lst1;
		lst1 = lst1->next_number;
		free(temp1);
	}
	while (lst2)
	{
		temp2 = lst2;
		lst2 = lst2->next_number;
		free(temp2);
	}
}
