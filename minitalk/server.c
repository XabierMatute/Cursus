/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:31:42 by xmatute-          #+#    #+#             */
/*   Updated: 2022/11/10 13:18:47 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reaction(int sig)
{
	static char	c = 32;

	if (sig == SIGUSR1)
	{
		c++;
	}
	if (sig == SIGUSR2)
	{
		write(1, &c, 1);
		c = 32;
	}
}

void	action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	reaction(sig);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: -> %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = action;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
