/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:39:45 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/30 01:01:24 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_specifier(char **format, va_list ap, t_str *st_str)
{
	st_str->specifier = **format;
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

static void	parse_precision(char **format, t_flag *st_flag)
{
	if (**format == '.')
	{
		st_flag->dot = true;
		(*format)++;
		if (ft_isdigit(**format))
			st_flag->precision = (size_t)ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

static void	parse_flag(char **format, t_flag *st_flag)
{
	while (**format && ft_strchr("-0# +", **format))
	{
		if (**format == '-')
			st_flag->minus = true;
		if (**format == '0')
			st_flag->zero = true;
		if (**format == '#')
			st_flag->sharp = true;
		if (**format == ' ')
			st_flag->space = true;
		if (**format == '+')
			st_flag->plus = true;
		(*format)++;
	}
	if (st_flag->plus)
		st_flag->space = false;
	if (st_flag->minus)
		st_flag->zero = false;
}

static void	parse_width(char **format, t_flag *st_flag)
{
	if (**format && ft_strchr("123456789", **format))
	{
		st_flag->width = (size_t)ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

bool	parse(char **format, va_list ap, t_str *st_str, t_flag *st_flag)
{
	char	*prev;

	prev = *format;
	(*format)++;
	if (**format && ft_strchr("0-# +", **format))
		parse_flag(format, st_flag);
	if (**format && ft_strchr("123456789", **format))
		parse_width(format, st_flag);
	if (**format && ft_strchr(".", **format))
		parse_precision(format, st_flag);
	if (**format && ft_strchr("cspdiuxX%", **format))
		parse_specifier(format, ap, st_str);
	else
	{
		parse_error(st_str, st_flag);
		*format = prev;
	}
	if (st_str->str == NULL)
		return (false);
	if (st_flag->dot && ft_strchr("diuxX", st_str->specifier))
		st_flag->zero = false;
	(*format)++;
	return (true);
}
