/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:19:06 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/26 16:38:07 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

list	*ft_lstnew(int number, char letter)
{
	list	*new_lst;
	new_lst = malloc(sizeof(list));
	if (!new_lst)
		return (0);
	new_lst->number = number;
	new_lst->stack_letter = letter;
	new_lst->position = 0;
	new_lst->is_above_center = 0;
	new_lst->cost = 0;
	new_lst->index = 0;
	new_lst->target_pos = NULL;
	new_lst->next_number = NULL;
	return (new_lst);
}

void	ft_lstadd_last(list **lst, list *new_node)
{
	list	*last;

	if (!lst || !new_node)
		return ;
	if (lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last = *lst;
	while (last->next_number != NULL)
		last = last->next_number;
	last->next_number = new_node;
}