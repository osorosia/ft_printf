/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:50:20 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/09 09:50:22 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	init_struct_print(t_str *st_str, t_flag *st_flag)
{
	t_print	st_print;
	size_t	print_size;

	(void)print_size;
	ft_memset(&st_print, 0, sizeof(t_print));
	st_print.size = st_str->size;
	// if (st_flag->precision > 0
	// 	&& st_print.size > st_flag->precision
	// 	&& ft_strchr("s", st_str->specifier))
	// 	st_print.size = st_flag->precision;
	if (st_str->minus)
		st_print.sign = 1;
	if (st_str->specifier == 'p')
		st_print.hex = 2;
	if (st_flag->precision > st_print.size)
		st_print.zero = st_flag->precision - st_print.size;
	print_size = st_print.size + st_print.sign + st_print.hex;
	if (!st_flag->zero && st_flag->width > print_size)
		st_print.space = st_flag->width - print_size;
	if (st_flag->zero && st_flag->width > print_size)
		st_print.zero = st_flag->width - print_size;
	return (st_print);
}
