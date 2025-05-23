/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:30:02 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/02 15:31:19 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(t_list **lst)
{
	t_list	*tmp_head;
	t_list	*tmp_second;
	t_list	*tmp_third;

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

void	px(t_list **lst1, t_list **lst2)
{
	t_list	*new_top_lst1;
	t_list	*new_top_lst2;
	char	stack_letter;

	if (ft_lst_size(*lst1) == 0)
		return ;
	new_top_lst2 = *lst1;
	stack_letter = new_top_lst2->stack_letter;
	new_top_lst1 = new_top_lst2->next_number;
	if (new_top_lst2->stack_letter == 'a')
		new_top_lst2->stack_letter = 'b';
	else
		new_top_lst2->stack_letter = 'a';
	new_top_lst2->next_number = NULL;
	ft_lstadd_front(lst2, new_top_lst2);
	*lst1 = new_top_lst1;
	if (stack_letter == 'a')
		write (1, "pb\n", 3);
	else
		write (1, "pa\n", 3);
}

void	rx(t_list **lst)
{
	t_list	*head;
	t_list	*new_head;
	t_list	*last;

	if (ft_lst_size(*lst) < 2)
		return ;
	head = *lst;
	new_head = head->next_number;
	last = ft_lstlast(*lst);
	last->next_number = head;
	head->next_number = NULL;
	*lst = new_head;
	if (new_head->stack_letter == 'a')
		write (1, "ra\n", 3);
	else
		write (1, "rb\n", 3);
}

void	rrx(t_list **lst)
{
	t_list	*new_head;
	t_list	*new_last;

	if (ft_lst_size(*lst) < 2)
		return ;
	new_last = *lst;
	while (new_last->next_number->next_number)
		new_last = new_last->next_number;
	new_head = new_last->next_number;
	new_last->next_number = NULL;
	new_head->next_number = *lst;
	*lst = new_head;
	if (new_head->stack_letter == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
