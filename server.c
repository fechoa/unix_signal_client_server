/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:28:46 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/25 18:34:33 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_signal	g_values;

static void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int fd, int num)
{
	unsigned int	new_num;

	new_num = 0;
	if (num < 0)
	{
		write(fd, "-", 1);
		new_num = num * -1;
	}
	else
		new_num = num;
	if (new_num >= 0 && new_num <= 9)
		ft_putchar_fd(fd, new_num + 48);
	else
	{
		ft_putnbr_fd(fd, new_num / 10);
		ft_putchar_fd(fd, new_num % 10 + 48);
	}
}

static void	ft_init(void)
{
	g_values.pow = 0;
	g_values.symbol = 0;
}

static void	ft_message(int num)
{
	if (num == SIGUSR1)
		g_values.symbol += 1 << (7 - g_values.pow);
	g_values.pow++;
	if (g_values.pow == 8)
	{
		ft_putchar_fd(1, g_values.symbol);
		ft_init();
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	(void)(argv);
	ft_init();
	pid = getpid();
	if (argc != 1)
	{
		write(1, "Error... The server program can have only 1 arg.\n", 48);
		write(1, "Example: ./server + ENTER\n.\n", 26);
		return (1);
	}
	write(1, "Server started\nPID: ", 20);
	ft_putnbr_fd(1, pid);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_message);
	signal(SIGUSR2, ft_message);
	while (666)
		pause();
	return (0);
}
