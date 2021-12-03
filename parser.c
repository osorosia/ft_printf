/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:39:45 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 10:40:03 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_putnstr_fd(char *str, size_t n, int fd)
{
	if (fd < 0)
		return ;
	write(fd, str, n);
}

static void	parse_conversion(const char **format, va_list ap, t_str *st_str)
{
	if (**format == 'c')
		get_c(ap, st_str);
	if (**format == 's')
		get_s(ap, st_str);
	if (**format == 'p')
		get_p(ap, st_str);
	if (**format == 'd' || **format == 'i')
		get_d(ap, st_str);
	if (**format == 'u')
		get_u(ap, st_str);
	if (**format == 'x')
		get_x(ap, st_str);
	if (**format == 'X')
		get_xx(ap, st_str);
	if (**format == '%')
		get_per(st_str);
}

static void	parse_flag(const char **format, t_flag *st_flag)
{
	while (ft_strchr("-0", **format))
	{
		if (**format == '-')
			st_flag->minus = true;
		if (**format == '0')
			st_flag->zero = true;
		(*format)++;
	}
	if (ft_strchr("123456789", **format))
	{
		st_flag->width = (size_t)ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

static size_t	_print(t_str st_str, t_flag st_flag)
{
	size_t	print_size;

	print_size = 0;
	while (!st_flag.minus && st_flag.width-- > st_str.size)
	{
		if (st_flag.zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		print_size++;
	}
	_putnstr_fd(st_str.str, st_str.size, 1);
	print_size += st_str.size;
	while (st_flag.minus && st_flag.width-- > st_str.size)
	{
		ft_putchar_fd(' ', 1);
		print_size++;
	}
	return (print_size);
}

size_t	parse_format(const char **format, va_list ap)
{
	t_str	st_str;
	t_flag	st_flag;
	size_t	print_size;

	st_str.str = NULL;
	st_flag.width = 0;
	st_flag.minus = false;
	st_flag.zero = false;
	(*format)++;
	if (ft_strchr("0-123456789", **format))
		parse_flag(format, &st_flag);
	if (ft_strchr("cspdiuxX%", **format))
		parse_conversion(format, ap, &st_str);
	if (st_str.str == NULL)
		return ((size_t)SIZE_MAX);
	(*format)++;
	print_size = _print(st_str, st_flag);
	free(st_str.str);
	return (print_size);
}
