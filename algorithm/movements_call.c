/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:42:49 by ekeller-          #+#    #+#             */
/*   Updated: 2025/03/31 12:05:39 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push.h"

void    perform_rr(list **lst1, list **lst2, list *lower_cost_node)
{
    while (*lst1 != lower_cost_node->target_pos && *lst2 != lower_cost_node)
        rr(lst1, lst2);
    update_pos(lst1);
    update_pos(lst2);
}

void    perform_rrr(list **lst1, list **lst2, list *lower_cost_node)
{
    while (*lst1 != lower_cost_node->target_pos && *lst2 != lower_cost_node)
        rrr(lst1, lst2);
    update_pos(lst1);
    update_pos(lst2);
}

void    ft_finish_rotation(list **lst, list *lower_cost)
{
    while (*lst != lower_cost)
    {
        if (lower_cost->is_above_center == 1)
            rx(lst);
        else
            rrx(lst);
    }
}

void    perform_fianl_ra_rra(list **lst)
{
    list    *smallest_node;

    smallest_node = get_smallest_node(lst);
    if (smallest_node->is_above_center == 1)
    {
        while (*lst != smallest_node)
            rx(lst);
    }
    else if (smallest_node->is_above_center == 0)
    {    
        while (*lst != smallest_node)
            rrx(lst);
    }
}