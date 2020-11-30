/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:33:10 by pae-andrew        #+#    #+#             */
/*   Updated: 2020/11/08 18:54:10 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*copy;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(copy = ft_strdup((const char *)s)))
		return (NULL);
	while (copy[i])
	{
		copy[i] = f((unsigned int)i, copy[i]);
		i++;
	}
	return (copy);
}
