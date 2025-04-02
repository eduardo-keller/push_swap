/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:32:49 by ekeller-          #+#    #+#             */
/*   Updated: 2025/04/02 17:36:56 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	update_pos(t_list **lst)
{
	t_list	*current;
	int		position;
	int		center_line;

	current = *lst;
	position = 0;
	center_line = (ft_lst_size(*lst) - 1) / 2;
	while (current)
	{
		current->position = position;
		if (position <= center_line)
			current->is_above_center = 1;
		else if (position > center_line)
			current->is_above_center = 0;
		position++;
		current = current->next_number;
	}
}

t_list	*get_lower_cost_node(t_list **lst)
{
	t_list	*current;
	t_list	*lower_cost;

	current = *lst;
	lower_cost = current;
	while (current)
	{
		if (current->cost < lower_cost->cost)
			lower_cost = current;
		current = current->next_number;
	}
	return (lower_cost);
}

t_list	*get_smallest_node(t_list **lst)
{
	t_list	*smallest;
	t_list	*current;
	int		temp_min;

	current = *lst;
	smallest = current;
	temp_min = current->index;
	while (current)
	{
		if (current->index < temp_min)
		{
			temp_min = current->index;
			smallest = current;
		}
		current = current->next_number;
	}
	return (smallest);
}

t_list	*get_biggest_node(t_list **lst)
{
	t_list	*biggest_node;
	t_list	*current;

	current = *lst;
	biggest_node = current;
	while (current)
	{
		if (current->index > biggest_node->index)
			biggest_node = current;
		current = current->next_number;
	}
	return (biggest_node);
}

int	ft_greater(int pos1, int pos_targ)
{
	if (pos1 > pos_targ)
		return (pos1);
	else
		return (pos_targ);
}
