/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:33:48 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/28 18:04:12 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h> //exclude

typedef struct list
{
	int		number;
	int		index;
	int		position;
	int		is_above_center;
	int 	cost;
	char	stack_letter;
	struct list	*target_pos;
	struct list	*next_number;
} list;

//input_validator.c
char	**input_argv_validator(int argc, char **argv);
int		input_argc_validator(int argc, char **argv);
int		input_validator(int argc, char **argv);
int	input_duplicates_validator(list **lst);

//validator_ultils.c
int		ft_nbr(char *nbr);
int		input_item_validator(int argc, char ** argv);

//stack_builder.c
list *stack_builder(int argc, char **argv);
void	assign_index(list *head, int current_index);

//linked_lst_utils.c
list	*ft_lstnew(int number, char letter);
void	ft_lstadd_last(list **lst, list *new_node);
int		ft_lst_size(list *lst);

//movements.c
void	swap(list **lst);

//prep_stack_a.c         to be done
//defines a target position for all nodes in a, which is the best position
//for node a to be pushed to b so that stack b is ordered from highest to lowest.
//this target is the largest index in B that is smaller than index A. best_match is
//used to hold the current highest number in B that is smaller than A until the
//iteration in B finishes. if node a is smaller than all B, target for node A is
//at the top of highest B so that it can be easilly rotated to the bottom of B. 
static void	update_target_pos_in_b(t_elem **lst1, t_elem **lst2);
//estimates how many moves it will take to take node A to the top of stack A, 
//plus how many moves it will take to bring its target position in stack B 
//to the top of stack B, so that node A can be push to its target position in B
//after pushing A to B. 1) A position and target position are in the top half of each
//stack, so choose the furthest position as cost (use R-R and after RX). 2) both are
// at bottom half, choose the max of distance to bottom A and B (use RR-R and after RRX).
//3)A top half and B bottom half. cost = a_position + distance of B to bottom B. 
//rotate A up and rotate B down. 4) inverse of 3.
//from the logic of move_elems_to_b, the cost for pushing each node A to B
//is recalculated everytime a node A is pushed to B. 
static void	cal_cost_a(t_elem **lst1, t_elem **lst2);
//defines position in the stack. defines ideal target positions for
//pushing A into B. target position and cost is recalculated after every 
//push from A to B. calculate cost for pushing each node A into B.
//return node with lowest cost. 
static t_elem	*ft_init_a(t_elem **lst1, t_elem **lst2);

//split.c
char	**ft_split(char const *s, char c);
size_t	count_words(char const *s, char c);
void	ft_free_split(char **s, size_t current_word);

//split_utils.c
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);

long	ft_atol(char *str);