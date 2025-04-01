/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:45:57 by ekeller-          #+#    #+#             */
/*   Updated: 2025/04/01 15:55:40 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//find best position for node B in A, which is the smallest index in A
//that is bigger than B. if B is bigger than all A, push B on top of smallest A
//so it can be easilly rotated to the bottom;
static void	ft_target_pos_a(t_list **lst1, t_list **lst2)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*target;
	long	best_match;

	node2 = *lst2;
	while (node2)
	{
		best_match = LONG_MAX;
		node1 = *lst1;
		while (node1)
		{
			if (node1->index > node2->index && node1->index < best_match)
			{
				best_match = node1->index;
				target = node1;
			}
			node1 = node1->next_number;
		}
		if (best_match == LONG_MAX)
			node2->target_pos = get_smallest_node(lst1);
		else
			node2->target_pos = target;
		node2 = node2->next_number;
	}
}

static void	cal_cost_b(t_list **lst1, t_list **lst2)
{
	t_list	*node2;

	node2 = *lst2;
	while (node2)
	{
		if (node2->target_pos->is_above_center == 1 && \
			node2->is_above_center == 1)
			node2->cost = ft_greater(node2->position, \
			node2->target_pos->position);
		else if (node2->target_pos->is_above_center == 0 \
				&& node2->is_above_center == 0)
				node2->cost = ft_greater((ft_lst_size(*lst2) - \
				node2->position), (ft_lst_size(*lst1) - \
				node2->target_pos->position));
		else if (node2->target_pos->is_above_center == 1 \
				&& node2->is_above_center == 0)
			node2->cost = node2->target_pos->position + \
			(ft_lst_size(*lst2) - node2->position);
		else
			node2->cost = (ft_lst_size(*lst1) - node2->target_pos->position) \
			+ node2->position;
		node2 = node2->next_number;
	}
}

t_list	*ft_init_b(t_list **lst1, t_list **lst2)
{
	t_list	*lower_cost;

	update_pos(lst1);
	update_pos(lst2);
	ft_target_pos_a(lst1, lst2);
	cal_cost_b(lst1, lst1);
	lower_cost = get_lower_cost_node(lst2);
	return (lower_cost);
}

void	ft_move_b(t_list **lst1, t_list **lst2, t_list *lower_cost_node)
{
	if (lower_cost_node->is_above_center == 1 && \
		lower_cost_node->target_pos->is_above_center == 1)
		perform_rr(lst1, lst2, lower_cost_node);
	else if (lower_cost_node->is_above_center == 0 && \
		lower_cost_node->target_pos->is_above_center == 0)
		perform_rrr(lst1, lst2, lower_cost_node);
	ft_finish_rotation(lst2, lower_cost_node);
	ft_finish_rotation(lst1, lower_cost_node->target_pos);
	px(lst2, lst1);
}
