/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:36:10 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/07 16:35:20 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write (fd, "-", 1);
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = nb % 10 + '0';
	write(fd, &c, 1);
}

void	w_strategy(int strategy, double disorder)
{
	if (strategy == 0 || strategy == 1)
	{
		write(1, "Adaptive / ", 11);
		if (disorder < 0.2)
			write (2, "O(n2)\n", 6);
		else if (disorder >= 0.2 && disorder < 0.5)
			write (2, "O(n√n)\n", 7);
		else
			write (2, "O(n log n)\n", 11);
	}
	else if (strategy == 2)
		wirte (2, "Simple / O(n2)\n", 15);
	else if (strategy == 3)
		write (2, "Medium / O(n√n)\n", 16);
	else
		write (2, "Complex / O(n log n)\n", 21);
}

static void	w_op(t_data *data)
{
	write(2, "sa: ", 4);
	ft_putnbr_fd(data->bench.sa, 2);
	write(2, "  sb: ", 6);
	ft_putnbr_fd(data->bench.sb, 2);
	write(2, "  ss: ", 6);
	ft_putnbr_fd(data->bench.ss, 2);
	write(2, "  pa: ", 6);
	ft_putnbr_fd(data->bench.pa, 2);
	write(2, "  pb: ", 6);
	ft_putnbr_fd(data->bench.pb, 2);
	write(2, "\nra: ", 5);
	ft_putnbr_fd(data->bench.ra, 2);
	write(2, "  rb: ", 6);
	ft_putnbr_fd(data->bench.rb, 2);
	write(2, "  rr: ", 6);
	ft_putnbr_fd(data->bench.rr, 2);
	write(2, "  rra: ", 7);
	ft_putnbr_fd(data->bench.rra, 2);
	write(2, "  rrb: ", 7);
	ft_putnbr_fd(data->bench.rrb, 2);
	write(2, "  rrr: ", 7);
	ft_putnbr_fd(data->bench.rrr, 2);
	write(2, "\n", 1);
}

void	print_bench(t_data *data, t_flags flags)
{
	int		total_op;
	double	disorder_perc;

	total_op = data->bench.pa + data->bench.pb
		+ data->bench.sa + data->bench.sb + data->bench.ss
		+ data->bench.ra + data->bench.rb + data->bench.rr
		+ data->bench.rra + data->bench.rrb + data->bench.rrr;
	write (2, "disorder:	", 10);
	disorder_perc = flags.disorder * 100;
	ft_putnbr_fd(disorder_perc, 2);
	write (2, ".00%\n", 6);
	write (2, "strategy:	", 10);
	w_strategy(flags.strategy, flags.disorder);
	write(2, "total_ops:	", 11);
	ft_putnbr_fd(total_op, 2);
	w_op(data);
}
