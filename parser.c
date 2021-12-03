/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:39:45 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 07:29:11 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr_fd(char *str, size_t n, int fd)
{
	if (fd < 0)
		return ;
	write(fd, str, n);
}

static void parse_conversion(const char **format, va_list ap, t_str *st_str)
{
	if (**format == 'c')
		get_c(ap, st_str);
	if (**format == 's')
		get_s(ap, st_str);
	if (**format == 'p')
		get_p(ap, st_str);
	if (**format == 'd' || **format == 'i')
		get_d(ap, st_str);
}

size_t	parse_format(const char **format, va_list ap)
{
	t_str	st_str;

	st_str.str = NULL;
	(*format)++;
	if (ft_strchr("cspdiuxX%", **format))
		parse_conversion(format, ap, &st_str);
	if (st_str.str == NULL)
		return ((size_t)SIZE_MAX);
	(*format)++;
	ft_putnstr_fd(st_str.str, st_str.size, STDOUT_FILENO);
	free(st_str.str);
	return (st_str.size);
}
