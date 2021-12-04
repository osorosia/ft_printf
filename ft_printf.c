/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:53:50 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/04 08:38:47 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_calc_print_size(size_t print_size, size_t pre_size)
{
	if (print_size > (size_t)SIZE_MAX - pre_size)
		return ((size_t)SIZE_MAX);
	return (print_size + pre_size);
}

void init_struct(t_str *st_str, t_flag *st_flag)
{
	st_str->str = NULL;
	st_str->minus = false;
	st_str->size = 0;
	st_flag->width = 0;
	st_flag->precision = 0;
	st_flag->minus = false;
	st_flag->zero = false;
}

static int	_vprintf(const char *format, va_list ap)
{
	size_t	print_size;
	size_t	pre_size;
	t_str	st_str;	
	t_flag	st_flag;	

	print_size = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			init_struct(&st_str, &st_flag);
			parse(&format, ap, &st_str, &st_flag);
			pre_size = print(&st_str, &st_flag);
			print_size = _calc_print_size(print_size, pre_size);
		}
		else
		{
			ft_putchar_fd(*(format++), STDOUT_FILENO);
			print_size++;
		}
		if (print_size >= INT_MAX)
			return (-1);
	}	
	return ((int)print_size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_size;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	print_size = _vprintf(format, ap);
	va_end(ap);
	return (print_size);
}
