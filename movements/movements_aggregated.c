/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_aggregated.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:22:18 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/01 16:44:55 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ss(t_list **lst1, t_list **lst2)
{
	t_list	*tmp_head;
	t_list	*tmp_swap;
	t_list	*tmp_third;

	if (ft_lst_size(*lst1) < 2 && ft_lst_size(*lst2) < 2)
		return ;
	tmp_head = *lst1;
	tmp_swap = tmp_head->next_number;
	tmp_third = tmp_swap->next_number;
	tmp_head->next_number = tmp_third;
	*lst1 = tmp_swap;
	tmp_swap->next_number = tmp_head;
	tmp_head = *lst2;
	tmp_swap = tmp_head->next_number;
	tmp_third = tmp_swap->next_number;
	tmp_head->next_number = tmp_third;
	*lst2 = tmp_swap;
	tmp_swap->next_number = tmp_head;
	write(1, "ss\n", 3);
}

void	rr(t_list **lst1, t_list **lst2)
{
	t_list	*tmp_head;
	t_list	*new_top;
	t_list	*tmp_last;

	if (ft_lst_size(*lst1) < 2 && ft_lst_size(*lst2) < 2)
		return ;
	tmp_head = *lst1;
	new_top = tmp_head->next_number;
	tmp_last = ft_lstlast(*lst1);
	tmp_last->next_number = tmp_head;
	tmp_head->next_number = NULL;
	*lst1 = new_top;
	tmp_head = *lst2;
	new_top = tmp_head->next_number;
	tmp_last = ft_lstlast(*lst2);
	tmp_last->next_number = tmp_head;
	tmp_head->next_number = NULL;
	*lst2 = new_top;
	write(1, "rr\n", 3);
}

void	rrr(t_list **lst1, t_list **lst2)
{
	t_list	*new_top;
	t_list	*new_second;
	t_list	*new_last;

	if (ft_lst_size(*lst1) < 2 && ft_lst_size(*lst2) < 2)
		return ;
	new_second = *lst1;
	new_top = ft_lstlast(*lst1);
	new_last = *lst1;
	while (new_last->next_number != new_top)
		new_last = new_last->next_number;
	new_last->next_number = NULL;
	new_top->next_number = new_second;
	*lst1 = new_top;
	new_second = *lst2;
	new_top = ft_lstlast(*lst2);
	new_last = *lst2;
	while (new_last->next_number != new_top)
		new_last = new_last->next_number;
	new_last->next_number = NULL;
	new_top->next_number = new_second;
	*lst2 = new_top;
	write(1, "rrr\n", 4);
}
