/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:24:59 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 19:26:58 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print(t_str st_str, t_flag st_flag)
{
	size_t	print_size;

	print_size = 0;
	if (st_str.minus)
	{
		ft_putchar_fd('-', 1);
		print_size++;
	}
	while (!st_flag.minus && st_flag.width-- > st_str.size)
	{
		if (st_flag.zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		print_size++;
	}
	ft_putnstr_fd(st_str.str, st_str.size, 1);
	print_size += st_str.size;
	while (st_flag.minus && st_flag.width-- > st_str.size)
	{
		ft_putchar_fd(' ', 1);
		print_size++;
	}
	return (print_size);
}
