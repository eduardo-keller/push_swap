/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:18:37 by ekeller-          #+#    #+#             */
/*   Updated: 2025/03/30 16:42:31 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push.h"

//defines a target position for all nodes in a, which is the best position
//for node a to be pushed to b so that stack b is ordered from highest to lowest.
//this target is the largest index in B that is smaller than index A. best_match is
//used to hold the current highest number in B that is smaller than A until the
//iteration in B finishes. if node a is smaller than all B, target for node A is
//at the top of highest B so that it can be easilly rotated to the bottom of B. 
static void	update_target_pos_b(list **lst1, list **lst2)
{
    list    *node1;
    list    *node2;
    list    *target;
    long    best_match;
    
    node1 = *lst1;
    while (node1)
    {
        best_match = LONG_MIN;
        node2 = *lst2;
        while (node2)
        {
            if (node1->index > node2->index && node2->index > best_match)
            {
                best_match = node2->index;
                target = node2;
            }
            node2 = node2->next_number;
        }
        if (best_match == LONG_MIN)
            node1->target_pos = get_biggest_node(lst2);
        else
            node1->target_pos = target;
        node1 = node1->next_number;
    }
}

//estimates how many moves it will take to take node A to the top of stack A, 
//plus how many moves it will take to bring its target position in stack B 
//to the top of stack B, so that node A can be pushed to its target position in B
//after pushing A to B. 1) A position and target position are in the top half of each
//stack, so choose the furthest position as cost (use R-R and after RX). 2) both are
// at bottom half, choose the max of distance to bottom A and B (use RR-R and after RRX).
//3)A top half and B bottom half. cost = a_position + distance of B to bottom B. 
//rotate A up and rotate B down. 4) inverse of 3.
//from the logic of move_elems_to_b, the cost for pushing each node A to B
//is recalculated everytime a node A is pushed to B. 
static void	cal_cost_a(list **lst1, list **lst2) //little change
{
    list    *node;

    node = *lst1;
    while (node)
    {
        if (node->is_above_center == 1 && node->target_pos->is_above_center == 1)
            node->cost = ft_greater(node->position, node->target_pos->position );
        else if (node->is_above_center == 0 && node->target_pos->is_above_center == 0)
            node->cost = ft_greater((ft_lst_size(*lst1) - node->position), (ft_lst_size(*lst2) - node->target_pos->position));
        else if (node->is_above_center == 1 && node->target_pos->is_above_center == 0)
            node->cost = node->position + (ft_lst_size(*lst2) - node->target_pos->position);
        else
            node->cost = ft_lst_size(*lst1) - node->position + node->target_pos->position;
    }
}

//defines position in the stack. defines ideal target positions for
//pushing A into B. target position and cost is recalculated after every 
//push from A to B. calculate cost for pushing each node A into B.
//return node with lowest cost. 
static list	*ft_init_a(list **lst1, list **lst2)
{
    list    *lower_cost;
    
    update_pos(lst1);
    update_pos(lst2);
    update_target_pos_b(lst1, lst2);
    cal_cost_a(lst1, lst2);
    lower_cost = get_lower_cost_node(lst1);
    return (lower_cost);
}

//perform joint rotations ultil node or target node reachs top. perform individual
//rotations until remaining node reaches position. push lower cost node to b.
static void	ft_move_a(list **lst1, list **lst2, list *lower_cost_node)
{
    if (lower_cost_node->is_above_center == 1 && lower_cost_node->next_number->is_above_center == 1)
        perform_rr(lst2, lst1, lower_cost_node);
    if (lower_cost_node->is_above_center == 0 && lower_cost_node->next_number->is_above_center == 1)
        perform_rrr(lst2, lst1, lower_cost_node);
    ft_finish_rotation(lst1, lower_cost_node);
    ft_finish_rotation(lst2, lower_cost_node->target_pos);
    px(lst1, lst2);
}
//push the first 2 nodes to B. Calculate targets and costs of pushing each
//node from A to B and push node with smallest cost to B;
void	move_elems_to_b(list **lst1, list **lst2)
{
    list    *lower_cost_node;

    if (ft_lst_size(*lst1) > 3 && check_ordered(*lst1) == 0)
        px(lst1, lst2);
    if (ft_lst_size(*lst1) > 3 && check_ordered(*lst1) == 0)
        px(lst1, lst2);
    while (ft_lst_size(*lst1) > 3 && check_ordered(*lst1) == 0)
    {
        lower_cost_node = ft_init_a(lst1, lst2);
        ft_move_a(lst1, lst2, lower_cost_node);
    }
}