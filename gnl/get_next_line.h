/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:27:04 by xmatute-          #+#    #+#             */
/*   Updated: 2022/10/18 17:35:18 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
// # include <stdio.h>
// # include <fcntl.h>

char	*ft_strjoinfree(char *s1, char *s2);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlen(const char *s);

#endif