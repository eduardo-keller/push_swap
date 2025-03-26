/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:33:48 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/26 17:18:26 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct list
{
	int		number;
	int		index;
	int		position;
	int		is_above_center;
	int 	cost;
	char	stack_letter;
	list	*target_pos;
	list	*next_number;
} list;

//input_validator.c
char	**input_argv_validator(int argc, char **argv);
int		input_argc_validator(int argc, char **argv);
int		input_validator(int argc, char **argv);
int		input_item_validator(int argc, char ** argv);

//validator_ultils.c
int		ft_nbr(char *nbr);

//stack_builder.c
list *stack_builder(int argc, char **argv);

//split.c
char	**ft_split(char const *s, char c);
size_t	count_words(char const *s, char c);
void	ft_free_split(char **s, size_t current_word);

//split_utils.c
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);

long	ft_atol(char *str);