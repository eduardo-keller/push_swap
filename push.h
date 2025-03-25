#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//input_validator.c
char	**input_argv_validator(int argc, char **argv);
int		input_argc_validator(int argc, char **argv);
int		input_validator(int argc, char **argv);
int		input_item_validator(int argc, char ** argv);

//validator_ultils.c
int		ft_nbr(char *nbr);

//split.c
char	**ft_split(char const *s, char c);
size_t	count_words(char const *s, char c);
void	ft_free_split(char **s, size_t current_word);

//split_utils.c
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);