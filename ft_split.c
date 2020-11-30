/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:42:16 by eistario          #+#    #+#             */
/*   Updated: 2020/11/09 18:28:44 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		size_for_malloc(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0' && *s != c)
			i++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (i);
}

static size_t	size(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char		**ft_free(char **s, int i)
{
	while (i != 0)
	{
		free(s[i]);
		i--;
	}
	free(s[i]);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**a;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	if (!s || !(a = (char **)malloc(sizeof(char *)
				* (size_for_malloc(s, c) + 1))))
		return (0);
	while ((j = 0) || s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if (!(a[l] = (char *)malloc(sizeof(char) * (size(s + i, c) + 1))))
				return (ft_free(a, l));
			while (s[i] != '\0' && s[i] != c)
				a[l][j++] = s[i++];
			a[l++][j] = 0;
		}
	}
	a[l] = 0;
	return (a);
}
