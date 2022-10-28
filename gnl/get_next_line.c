/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:18:26 by xmatute-          #+#    #+#             */
/*   Updated: 2022/10/18 17:33:54 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*endb(char **buff, int *end)
{
	if (*buff)
		free(*buff);
	*end = 1;
	return (0);
}

char	*getbuffer(char	**buffer, size_t *i, int fd, int *end)
{
	int	r;

	if (!*buffer)
	{
		*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!*buffer)
			return (endb(buffer, end));
	}
	if (!buffer[0][0] || !buffer[0][*i])
	{
		r = read(fd, *buffer, BUFFER_SIZE);
		if (r < 1)
			return (endb(buffer, end));
		while (r < BUFFER_SIZE)
			buffer[0][r++] = 0;
		*i = 0;
	}
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer = 0;
	static size_t	i = 0;
	static int		end = 0;
	size_t			j;
	char			*line;

	if (BUFFER_SIZE < 1 || fd < 0 || end || !getbuffer(&buffer, &i, fd, &end))
		return (0);
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (endb(&buffer, &end));
	j = 0;
	while (ft_strlen(line) < BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
		line[j++] = buffer[i++];
	if (buffer[i] == '\n')
	{
		line[j] = buffer[i++];
		return (line);
	}
	else
		return (ft_strjoinfree(line, get_next_line(fd)));
}
