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
	perror_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit (0);
}

static int
	calc_rv(long count)
{
	if (count > 2147483647 || count < -2147483648)
		perror_exit();
	return (count);
}

void
	run_math_signs(const char **str, int *sign)
{
	if (*(*str) == '-' || *(*str) == '+')
	{
		if (*(*str) == '-')
			(*sign) = -1;
		else
			(*sign) = 1;
		(*str)++;
	}
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
	run_math_signs(&str, &sign);
	if (!(*str >= '0' && *str <= '9'))
		perror_exit();
	while (*str >= '0' && *str <= '9')
	{
		count *= 10;
		count += (*str - 48) * sign;
		str++;
	}
	while (*str == ' ' || (*str >= 9 && *str <= 13) || *str == 127)
		str++;
	if (*str)
		perror_exit();
	return (calc_rv(count));
}
