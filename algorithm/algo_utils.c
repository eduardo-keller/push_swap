/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:32:49 by ekeller-          #+#    #+#             */
/*   Updated: 2025/03/29 13:02:12 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push.h"

void    update_pos(list **lst)
{
    list    *current;
    int     position;
    int     center_line;
        
    current = *lst;
    position = 0;
    center_line = (ft_lst_size(lst) - 1) / 2;
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

list    *get_biggest_node(list **lst)
{
    list    *biggest_node;
    list    *current;

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

int ft_greater(int pos1, int pos_targ)
{
    if (pos1 > pos_targ)
        return (pos1);
    else
        return (pos_targ);
}