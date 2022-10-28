/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:48:42 by xmatute-          #+#    #+#             */
/*   Updated: 2022/10/18 17:34:05 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;
	size_t	i;

	p = malloc(nitems * size);
	if (!p)
		return (0);
	i = 0;
	while (i < nitems * size)
	{
		*((unsigned char *)(p + i)) = (unsigned char)0;
		i++;
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s2)
		return (s1);
	s = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!s)
		return (0);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	free(s1);
	free(s2);
	return (s);
}
