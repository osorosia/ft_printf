/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:50:20 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/09 10:32:09 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_get_size_of_space(t_print *st_print, t_str *st_str, t_flag *st_flag)
{
	size_t	space_size;
	size_t	other_size;
	
	(void)st_str;
	space_size = 0;
	other_size = st_print->size;
	other_size += st_print->sign;
	other_size += st_print->hex;
	other_size += st_print->zero;
	if (st_flag->width > other_size)
		space_size += st_flag->width - other_size;
	return (space_size);
}

static size_t	_get_size_of_zero(t_print *st_print, t_str *st_str, t_flag *st_flag)
{
	size_t	zero_size;
	size_t	other_size;

	(void)st_str;
	(void)st_flag;
	zero_size = 0;
	other_size = st_print->size;
	other_size += st_print->sign;
	other_size += st_print->hex;
	if (st_flag->zero && st_flag->width > other_size )
		zero_size = st_flag->width - other_size;
	return (zero_size);
}

static size_t	_get_base_size(t_str *st_str, t_flag *st_flag)
{
	(void)st_flag;
	return (st_str->size);
}

t_print	init_struct_print(t_str *st_str, t_flag *st_flag)
{
	t_print	st_print;
	size_t	print_size;

	(void)print_size;
	ft_memset(&st_print, 0, sizeof(t_print));
	st_print.size = _get_base_size(st_str, st_flag);
	if (st_str->minus)
		st_print.sign = 1;
	if (st_str->specifier == 'p')
		st_print.hex = 2;
	st_print.zero = _get_size_of_zero(&st_print, st_str, st_flag);
	st_print.space = _get_size_of_space(&st_print, st_str, st_flag);
	return (st_print);
}
