/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:28:40 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/25 18:28:52 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	long int	num;
	int			flag;

	num = 0;
	flag = 1;
	while (*str == ' ' || *str == '\r' || *str == '\f' || *str == '\v'
		|| *str == '\t')
		str++;
	if (*str == '-')
		flag = -1;
	while (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		str++;
	}
	num = num * flag;
	return ((int)num);
}

static void	ft_convert_char(int pid, char ch)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (ch >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Bad signal\n", 11);
				return ;
			}			
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "Bad signal\n", 11);
				return ;
			}
		}
		i--;
		usleep(600);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
	{
		write(1, "Error... Please give me 2 args: PID and \"Message text\"\n", 55);
		return (1);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		write(1, "Bad signal\n", 11);
		return (1);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_convert_char(ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	return (0);
}
