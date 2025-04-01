/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:28:52 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/01 16:15:45 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char **argv)
{
	int		validator;
	int		val_dup;
	t_list	*lst_a;
	t_list	*lst_b;

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
}
