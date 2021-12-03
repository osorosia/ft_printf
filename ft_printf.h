/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:03:18 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 07:10:13 by rnishimo         ###   ########.fr       */
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

typedef struct	s_str
{
	char	*str;
	size_t	size;
} t_str;

// main
int	ft_printf(const char *format, ...);

// parser
size_t	parse_format(const char **format, va_list ap);
void	get_c(va_list ap, t_str *st_str);
void	get_s(va_list ap, t_str *st_str);
void	get_p(va_list ap, t_str *st_str);
void	get_d(va_list ap, t_str *st_str);

// utils
size_t	calc_number_of_digit(long long num, const char *base);
size_t	calc_unsigned_number_of_digit(size_t num, const char *base);
void	set_number_base(char *str, long long num, const char *base);
void	set_unsigined_number_base(char *str, size_t num, const char *base);


#endif