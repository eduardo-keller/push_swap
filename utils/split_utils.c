/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:29:17 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/25 15:29:18 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	len_s;

	len_s = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[len_s])
		len_s++;
	if (start >= len_s)
		return (ft_calloc(1, sizeof(char)));
	if (len > len_s - start)
		len = len_s - start;
	sub_s = malloc(len + 1);
	if (!sub_s)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	total_mem;
	size_t	i;
	size_t	max_size;

	i = 0;
	max_size = ~(size_t)0;
	total_mem = nmemb * size;
	if (size != 0 && nmemb > max_size / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < total_mem)
		str[i++] = '\0';
	return (str);
}