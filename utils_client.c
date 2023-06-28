/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:22:35 by lhanna            #+#    #+#             */
/*   Updated: 2022/03/25 17:23:16 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*my_str;

	my_str = (char *)(str);
	i = 0;
	while (my_str[i] != '\0')
	{
		if (my_str[i] == c)
		{
			return (&my_str[i]);
		}
		i++;
	}
	if (my_str[i] == c)
	{
		return (&my_str[i]);
	}
	return (0);
}

int	check_num(long num)
{
	if (num > 2147483647)
		return (-1);
	if (num < -2147483648)
		return (0);
	return ((int)num);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;
	long	i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (long)(str[i] - '0');
		i++;
	}
	return (check_num((long)sign * res));
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
