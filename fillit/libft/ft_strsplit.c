/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:29:03 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/05 21:54:43 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static size_t	words_len(char const *s, char c)
{
	size_t	len;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			len++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (len);
}

static int		free_tab(char **s)
{
	while (*s != NULL)
	{
		free(*s);
		s++;
	}
	free(s);
	return (1);
}

static int		skip(const char **s, char c)
{
	while (**s == c)
	{
		(*s)++;
		if (**s == '\0')
			return (1);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**out;
	char	*word;
	int		i;
	size_t	tmp;

	i = -1;
	tmp = words_len(s, c);
	if (!s || !(out = (char **)malloc(sizeof(char *) * (tmp + 1))))
		return (NULL);
	out[tmp] = NULL;
	while (*s != 0)
	{
		if (skip(&s, c))
			break ;
		tmp = word_len(s, c);
		word = (char *)malloc(sizeof(char) * (tmp + 1));
		if (!word)
			if (free_tab(out))
				return (NULL);
		ft_strncpy(word, s, tmp);
		word[tmp] = '\0';
		out[(++i)] = word;
		s += tmp;
	}
	return (out);
}
