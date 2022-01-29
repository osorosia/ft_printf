/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:39:45 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/29 20:55:24 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_specifier(const char **format, va_list ap, t_str *st_str)
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

static void	parse_precision(const char **format, t_flag *st_flag)
{
	(void)st_flag;
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

static void	parse_flag(const char **format, t_flag *st_flag)
{
	while (ft_strchr("-0# +", **format))
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

static void	parse_width(const char **format, t_flag *st_flag)
{
	if (ft_strchr("123456789", **format))
	{
		st_flag->width = (size_t)ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	parse(const char **format, va_list ap, t_str *st_str, t_flag *st_flag)
{
	(*format)++;
	if (ft_strchr("0-# +", **format))
		parse_flag(format, st_flag);
	if (ft_strchr("123456789", **format))
		parse_width(format, st_flag);
	if (ft_strchr(".", **format))
		parse_precision(format, st_flag);
	if (ft_strchr("cspdiuxX%", **format))
		parse_specifier(format, ap, st_str);
	if (st_str->str == NULL)
		return ;
	(*format)++;
}
