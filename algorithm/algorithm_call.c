/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:58:40 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/01 16:33:20 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	final_algorithm(t_list **lst_1, t_list **lst_2)
{
	int	lst_size;

	lst_size = ft_lst_size(*lst_1);
	if (lst_size == 2)
	{	
		algo_case_1(lst_1);
		return ;
	}
	if (lst_size == 3)
	{	
		algo_case_2(lst_1);
		return ;
	}
	if (lst_size > 3)
	{	
		algo_case_3(lst_1, lst_2);
		return ;
	}
	return ;
}

//move elements to B reverse sorted until 3 elements left in A.
//order A. move elements to A which will be sorted but not
//necessarily in ascending order. perform final sorting rr. 
void	algo_case_3(t_list **lst1, t_list **lst2)
{
	t_list	*lower_cost_node;

	move_elems_to_b(lst1, lst2);
	if (check_ordered(*lst1) == 0)
		algo_case_2(lst1);
	while (ft_lst_size(*lst2) != 0)
	{
		lower_cost_node = ft_init_b(lst1, lst2);
		ft_move_b(lst1, lst2, lower_cost_node);
	}
	update_pos(lst1);
	perform_final_ra_rra(lst1);
}

void	algo_case_1(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	next = current->next_number;
	if (current->index > next->index)
		swap(lst);
	return ;
}

void	algo_case_2(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *lst;
	second = first->next_number;
	third = second->next_number;
	if (first->index > second->index && first->index > third->index)
		rx(lst);
	if (second->index > first->index && second->index > third->index)
		rrx(lst);
	first = *lst;
	second = first->next_number;
	if (first->index > second->index)
		swap(lst);
}

int	check_ordered(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
		return (0);
	current = lst;
	while (current)
	{
		if (current->index > current->next_number->index)
			return (0);
		current = current->next_number;
	}
	return (1);
}
