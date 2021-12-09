/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:24:59 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/09 09:49:50 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_print_space(t_print *st_print)
{
	size_t	i;

	i = 0;
	while (i++ < st_print->space)
		ft_putchar_fd(' ', STDOUT_FILENO);
}

static void	_print_zero(t_print *st_print)
{
	size_t	i;

	i = 0;
	if (i++ < st_print->zero)
		ft_putchar_fd('0', STDOUT_FILENO);
}

static void	_print_sign_hex(t_str *st_str, t_print *st_print)
{
	if (st_print->sign)
	{
		if (st_str->minus)
			ft_putchar_fd('-', STDOUT_FILENO);
		else
			ft_putchar_fd('+', STDOUT_FILENO);
	}
	if (st_print->hex)
		ft_putstr_fd("0x", STDOUT_FILENO);
}

size_t	_print_size(t_print *st_print)
{
	size_t	print_size;

	print_size = st_print->size;
	print_size += st_print->space;
	print_size += st_print->zero;
	print_size += st_print->sign;
	print_size += st_print->hex;
	return (print_size);
}

size_t	print(t_str *st_str, t_flag *st_flag)
{
	t_print	st_print;

	st_print = init_struct_print(st_str, st_flag);
	if (st_str->str == NULL)
		return ((size_t)SIZE_MAX);
	if (!st_flag->minus)
		_print_space(&st_print);
	_print_sign_hex(st_str, &st_print);
	_print_zero(&st_print);
	ft_putnstr_fd(st_str->str, st_print.size, STDOUT_FILENO);
	if (st_flag->minus)
		_print_space(&st_print);
	free(st_str->str);
	return (_print_size(&st_print));
}
