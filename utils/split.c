/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:29:01 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/03 11:37:54 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static size_t	ft_word_len(char const *str, char c, size_t start)
{
	size_t	w_len;

	w_len = 0;
	while (str[start] != c && str[start] != '\0')
	{
		w_len++;
		start++;
	}
	return (w_len);
}

void	ft_free_split(char **s, size_t current_word)
{
	size_t	i;

	i = 0;
	while (i < current_word)
		free(s[i++]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	words;
	size_t	current_word;
	size_t	word_len;

	words = count_words(s, c);
	split = (char **)ft_calloc((words + 1), sizeof(char *));
	if (split == NULL)
		return (NULL);
	start = 0;
	current_word = -1;
	while (++current_word < words)
	{
		while (s[start] == c)
			start++;
		word_len = ft_word_len(s, c, start);
		split[current_word] = ft_substr(s, start, word_len);
		if (split[current_word] == NULL)
			ft_free_split(split, current_word);
		if (split == NULL)
			return (NULL);
		start += word_len;
	}
	return (split);
}
