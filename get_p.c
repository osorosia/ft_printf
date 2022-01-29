/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:43:17 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/29 21:41:36 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_p(va_list ap, t_str *st_str)
{
	size_t		p;
	const char	*base = "0123456789abcdef";
	const int	base_size = 16;

	p = va_arg(ap, size_t);
	if ((size_t)p == 0)
		st_str->zero = true;
	st_str->size = ft_numlen_u_base(p, base_size);
	st_str->str = (char *)malloc(sizeof(char) * (st_str->size + 1));
	if (st_str->str == NULL)
		return ;
	set_unsigned_number_base(st_str->str, p, base);
}
