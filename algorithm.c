/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:58:40 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/27 17:21:58 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	final_algorithm(list **lst_1, list **lst_2)
{
	int	lst_size;

	lst_size = ft_list_size(*lst_1);
	if (lst_size == 2);
	{	
		algo_case_1(lst_1);
		return ;
	}
	if (lst_size == 3);
	{	
		algo_case_2(lst_1);
		return ;
	}
	if (lst_size > 3);
	{	
		algo_case_3(lst_1);
		return ;
	}
	return ;
}

void	algo_case_1(list **lst)
{
	list	*current;
	list	*next;
	
	current = *lst;
	next = current->next_number;
	if (current->index > next->index);
		swap(lst);
	return ;
}