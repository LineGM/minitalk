/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:13:57 by lhanna            #+#    #+#             */
/*   Updated: 2022/03/25 17:17:50 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_len_receive(int *curr_bit, char **str, int *received, int s)
{
	static int	len_val = 0;

	if (s == SIGUSR2)
		len_val += ft_recursive_power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*received = 1;
		*str = ft_calloc_exit(len_val + 1, sizeof(char));
		*curr_bit = 0;
		len_val = 0;
		return ;
	}
	(*curr_bit)++;
}

static void	ft_reset(int *len_received, char **str, int *i)
{
	*len_received = 0;
	if (str)
	{
		ft_putendl_fd(*str, 1);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

static void	ft_receive(int signal)
{
	static int	char_value = 0;
	static int	current_bit = 0;
	static int	len_received = 0;
	static int	i = 0;
	static char	*final_str = 0;

	if (!len_received)
		ft_len_receive(&current_bit, &final_str, &len_received, signal);
	else
	{
		if (signal == SIGUSR2)
			char_value += ft_recursive_power(2, current_bit);
		if (current_bit == 7)
		{
			final_str[i++] = char_value;
			current_bit = 0;
			if (char_value == 0)
				return (ft_reset(&len_received, &final_str, &i));
			char_value = 0;
			return ;
		}
		current_bit++;
	}
}

int	main(void)
{
	int	id;

	id = (int)(getpid());
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receive);
	while (1)
		usleep(WAIT_TIME);
}
