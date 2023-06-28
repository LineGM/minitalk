/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:28:16 by lhanna            #+#    #+#             */
/*   Updated: 2022/03/25 17:51:58 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int			ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strchr(const char *str, int c);
int			check_num(long num);
int			ft_strlen(const char *str);
int			ft_recursive_power(int nb, int power);
void		*ft_calloc_exit(size_t count, size_t size);
void		ft_bzero(void *str, size_t n);

# define WAIT_TIME 100

#endif
