/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:53:50 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/29 22:16:44 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_add_and_check_overflow(size_t print_size, size_t pre_size)
{
	if (print_size > (size_t)SIZE_MAX - pre_size)
		return ((size_t)SIZE_MAX);
	return (print_size + pre_size);
}

void	init_struct(t_str *st_str, t_flag *st_flag)
{
	ft_memset(st_str, 0, sizeof(t_str));
	ft_memset(st_flag, 0, sizeof(t_flag));
}

static int	_vprintf(char *format, va_list ap)
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
			if (!parse(&format, ap, &st_str, &st_flag))
				return (-1);
			pre_size = print(&st_str, &st_flag);
			print_size = _add_and_check_overflow(print_size, pre_size);
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
	print_size = _vprintf((char *)format, ap);
	va_end(ap);
	return (print_size);
}
