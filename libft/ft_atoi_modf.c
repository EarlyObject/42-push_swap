/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:03:11 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/29 10:31:18 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	perrorexit(void)
{
	ft_putendl_fd("Error", 2);
	exit (0);
}

static int
	calcrv(long count)
{
	if (count > 2147483647 || count < -2147483648)
		perrorexit();
	return (count);
}

int
	ft_atoi_modf(const char *str)
{
	int		sign;
	long	count;

	sign = 1;
	count = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13) || *str == 127)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else
			sign = 1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		perrorexit();
	while (*str >= '0' && *str <= '9')
	{
		count *= 10;
		count += (*str - 48) * sign;
		str++;
	}
	while (*str == ' ' || (*str >= 9 && *str <= 13) || *str == 127)
		str++;
	if (*str)
		perrorexit();
	return (calcrv(count));
}
