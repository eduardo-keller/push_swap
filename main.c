/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:28:52 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/26 11:28:17 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char **argv)
{
	int	validator;
	list	lst_a;

	validator = input_validator(argc, argv);
	if (validator == 0)
	{
		write(2, "Error\n", 6);
	}
	lst_a = stack_builder(argc, argv);
	
}