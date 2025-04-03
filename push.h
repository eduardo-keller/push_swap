/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:33:48 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/03 11:58:53 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct t_list
{
	int				number;
	int				index;
	int				position;
	int				is_above_center;
	int				cost;
	char			stack_letter;
	struct t_list	*target_pos;
	struct t_list	*next_number;
}	t_list;

//algorithm_call.c
void	final_algorithm(t_list **lst_1, t_list **lst_2);
void	algo_case_3(t_list **lst1, t_list **lst2);
void	algo_case_1(t_list **lst);
void	algo_case_2(t_list **lst);
int		check_ordered(t_list *lst);

//algo_utils.c
void	update_pos(t_list **lst);
t_list	*get_lower_cost_node(t_list **lst);
t_list	*get_smallest_node(t_list **lst);
t_list	*get_biggest_node(t_list **lst);
int		ft_greater(int pos1, int pos_targ);

//movements_call.c
void	perform_rr(t_list **lst1, t_list **lst2, t_list *lower_cost_node);
void	perform_rrr(t_list **lst1, t_list **lst2, t_list *lower_cost_node);
void	ft_finish_rotation(t_list **lst, t_list *lower_cost);
void	perform_final_ra_rra(t_list **lst);

//input_validator.c
char	**input_argv_validator(int argc, char **argv);
int		input_argc_validator(int argc, char **argv);
int		input_validator(int argc, char **argv);
int		input_duplicates_validator(t_list **lst);

//validator_ultils.c
int		ft_nbr(char *nbr);
int		input_item_validator(int argc, char **argv);

//stack_builder.c
t_list	*stack_builder(int argc, char **argv);
void	assign_index(t_list *head, int current_index);

//linked_lst_utils.c
t_list	*ft_lstnew(int number, char letter);
void	ft_lstadd_last(t_list **lst, t_list *new_node);
int		ft_lst_size(t_list *lst);

//movements.c
void	swap(t_list **lst);
void	px(t_list **lst1, t_list **lst2);
void	rx(t_list **lst);
void	rrx(t_list **lst);

//movements_aggregated.c
void	ss(t_list **lst1, t_list **lst2);
void	rr(t_list **lst1, t_list **lst2);
void	rrr(t_list **lst1, t_list **lst2);

//prep_stack_a.c
void	move_elems_to_b(t_list **lst1, t_list **lst2);

//prep_stack_b.c
t_list	*ft_init_b(t_list **lst1, t_list **lst2);
void	ft_move_b(t_list **lst1, t_list **lst2, t_list *lower_cost_node);

//linked_lst_utils.c
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int number, char letter);
void	ft_lstadd_last(t_list **lst, t_list *new_node);
int		ft_lst_size(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new_node);

//split.c
char	**ft_split(char const *s, char c);
size_t	count_words(char const *s, char c);
void	ft_free_split(char **s, size_t current_word);

//split_utils.c
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
long	ft_atol(char *str);

void	free_lst(t_list *lst1, t_list *lst2);

#endif