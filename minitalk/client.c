/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:15:12 by xmatute-          #+#    #+#             */
/*   Updated: 2022/11/10 13:23:02 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendstr(int pid, char const *s)
{
	unsigned char	c;
	size_t			i;

	i = 0;
	while (s[i])
	{
		c = s[i];
		while (c != 32)
		{
			c--;
			kill(pid, SIGUSR1);
			usleep (42);
		}
		kill(pid, SIGUSR2);
		usleep (42);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	if (argc != 3)
		ft_printf("Error: Wrong number of arguments");
	else
		sendstr(ft_atoi(argv[1]), argv[2]);
	return (0);
}
