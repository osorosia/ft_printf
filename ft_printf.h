/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:03:18 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/10 18:39:29 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# include "./libft/libft.h"

typedef struct s_str
{
	char	*str;
	size_t	size;
	bool	minus;
	char	specifier;
}	t_str;

typedef struct s_flag
{
	size_t	width;
	size_t	precision;
	bool	minus;
	bool	zero;
	bool	dot;
	bool	sharp;
	bool	space;
	bool	plus;
}	t_flag;

typedef struct s_print
{
	size_t	size;
	size_t	space;
	size_t	zero;
	size_t	sign;
	size_t	hex;
}	t_print;

// main
int		ft_printf(const char *format, ...);
size_t	print(t_str *st_str, t_flag *st_flag);
t_print	init_struct_print(t_str *st_str, t_flag *st_flag);

// parser
void	parse(const char **format, va_list ap, t_str *st_str, t_flag *st_flag);
void	get_c(va_list ap, t_str *st_str);
void	get_s(va_list ap, t_str *st_str);
void	get_p(va_list ap, t_str *st_str);
void	get_d(va_list ap, t_str *st_str);
void	get_u(va_list ap, t_str *st_str);
void	get_x(va_list ap, t_str *st_str);
void	get_xx(va_list ap, t_str *st_str);
void	get_per(t_str *st_str);

// utils
void	set_number_base(char *str, long long num, const char *base);
void	set_unsigned_number_base(char *str, size_t num, const char *base);

#endif
