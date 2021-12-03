/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:24:59 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 19:58:46 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_print_space(t_str *st_str, t_flag *st_flag, size_t *print_size)
{
	if (st_flag->width > 0 && st_str->minus)
		st_flag->width--;
	while (st_flag->width-- > st_str->size)
	{
		ft_putchar_fd(' ', 1);
		(*print_size)++;
	}
}

static void	_print_zero(t_str *st_str, t_flag *st_flag, size_t *print_size)
{
	if (!st_flag->zero || st_flag->minus)
		return ;
	if (st_flag->width > 0 && st_str->minus)
		st_flag->width--;
	while (st_flag->width-- > st_str->size)
	{
		ft_putchar_fd('0', 1);
		(*print_size)++;
	}
}

static void	_print_sign(t_str *st_str, t_flag *st_flag, size_t *print_size)
{
	(void)st_flag;
	if (st_str->minus)
	{
		ft_putchar_fd('-', 1);
		(*print_size)++;
	}
}

size_t	print(t_str st_str, t_flag st_flag)
{
	size_t	print_size;

	(void)st_flag;
	print_size = 0;
	if (!st_flag.minus && !st_flag.zero)
		_print_space(&st_str, &st_flag, &print_size);
	_print_sign(&st_str, &st_flag, &print_size);
	_print_zero(&st_str, &st_flag, &print_size);
	ft_putnstr_fd(st_str.str, st_str.size, 1);
	print_size += st_str.size;
	if (st_flag.minus)
		_print_space(&st_str, &st_flag, &print_size);
	return (print_size);
}
