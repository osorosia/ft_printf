/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:43:17 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 07:04:05 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_p(va_list ap, t_str *st_str)
{
	size_t		p;
	const char	*base = "0123456789abcdef";

	p = va_arg(ap, size_t);
	st_str->size = calc_unsigned_number_of_digit(p, base) + 2;
	st_str->str = (char *)malloc(sizeof(char) * (st_str->size + 1));
	if (st_str->str == NULL)
		return ;
	st_str->str[0] = '0';
	st_str->str[1] = 'x';
	set_unsigined_number_base(st_str->str + 2, p, base);
}
