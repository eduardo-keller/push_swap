/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:30:02 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/27 16:54:31 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(list **lst)
{
	list	*tmp_head;
	list	*tmp_second;
	list	*tmp_third;

	if (ft_lst_size(*lst) < 2)
		return ;
	tmp_head = *lst;
	tmp_second = tmp_head->next_number;
	tmp_third = tmp_second->next_number;
	*lst = tmp_second;
	tmp_second->next_number = tmp_head;
	tmp_head->next_number = tmp_third;
	if (tmp_second->stack_letter == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

