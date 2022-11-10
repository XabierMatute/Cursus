/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:30:31 by xmatute-          #+#    #+#             */
/*   Updated: 2022/11/10 13:17:34 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	i--;
	while ((str[++i] >= '0') && (str[i] <= '9'))
		n = 10 * n + (str[i] - '0');
	return (n);
}
