/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:29:10 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/27 10:34:52 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_nbr(char *nbr)
{
	if (*nbr == '\0')
		return (0);
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (*nbr == '\0')
		return (0);
	while (*nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (0);
		nbr++;
	}
	return (1);
}

int	input_item_validator(int argc, char ** argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_nbr(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}