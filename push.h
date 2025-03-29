/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:33:48 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/29 10:23:47 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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



//prep_stack_a.c
void	move_elems_to_b(list **lst1, list **lst2);



//split.c
char	**ft_split(char const *s, char c);
size_t	count_words(char const *s, char c);
void	ft_free_split(char **s, size_t current_word);

//split_utils.c
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);

long	ft_atol(char *str);