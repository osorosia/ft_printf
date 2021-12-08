/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:24:59 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/08 13:36:08 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_print_space(t_str *st_str, t_flag *st_flag, size_t *print_size)
{
	(void)st_str;
	while (st_flag->width > *print_size)
	{
		ft_putchar_fd(' ', 1);
		(*print_size)++;
	}
}

static void	_print_zero(t_str *st_str, t_flag *st_flag, size_t *print_size)
{
	(void)st_str;
	if (!st_flag->zero || st_flag->minus)
		return ;
	while (st_flag->width > *print_size)
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		(*print_size)++;
	}
}

static void	_print_sign(t_str *st_str, t_flag *st_flag)
{
	(void)st_flag;
	if (st_str->minus)
		ft_putchar_fd('-', STDOUT_FILENO);
}

static void _print_hex(t_str *st_str, t_flag *st_flag)
{
	(void)st_flag;
	if (st_str->specifier == 'p')
		ft_putstr_fd("0x", STDOUT_FILENO);
}

static size_t	_calc_print_size(t_str *st_str, t_flag *st_flag)
{
	size_t	print_size;

	(void)st_flag;
	print_size = st_str->size;
	if (st_str->minus)
		print_size++;
	if (st_str->specifier == 'p')
		print_size += 2;
	return (print_size);
}

size_t	print(t_str *st_str, t_flag *st_flag)
{
	size_t	print_size;

	if (st_str->str == NULL)
		return ((size_t)SIZE_MAX);
	print_size = _calc_print_size(st_str, st_flag);
	if (!st_flag->minus && !st_flag->zero)
		_print_space(st_str, st_flag, &print_size);
	_print_sign(st_str, st_flag);
	_print_hex(st_str, st_flag);
	_print_zero(st_str, st_flag, &print_size);
	ft_putnstr_fd(st_str->str, st_str->size, 1);
	if (st_flag->minus)
		_print_space(st_str, st_flag, &print_size);
	free(st_str->str);
	return (print_size);
}
