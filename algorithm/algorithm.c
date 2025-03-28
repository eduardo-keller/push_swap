/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:58:40 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/29 11:04:45 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

//move elements to B reverse sorted until 3 elements left in A. order A.
//move elements to A which will be almost sorted. perform final sorting rr. 
void	algo_case_3(list **lst1, list **lst2)
{
	list	*lower_cost_node;

	move_elems_to_b(lst1, lst2);
	if (check_ordered(*lst1) == 0)
		algo_case_2(lst1);
	while (ft_lstsize(*lst2) != 0)
	{
		lower_cost_node = ft_init_b(lst1, lst2);
		ft_move_b(lst1, lst2, lower_cost_node);
	}
	update_pos(lst1);
	perform_final_ra_or_rra(lst1);
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

void	algo_case_2(list **lst)
{
	
}

int	check_ordered(list *lst)
{
	list	*current;

	if (lst = NULL)
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