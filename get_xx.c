/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 07:38:27 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/29 21:49:34 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_xx(va_list ap, t_str *st_str)
{
	unsigned int	num;
	const char		*base = "0123456789ABCDEF";
	const int		base_size = 16;

	num = va_arg(ap, unsigned int);
	if (num == 0)
		st_str->zero = true;
	st_str->size = ft_numlen_base(num, base_size);
	st_str->str = (char *)malloc(sizeof(char) * (st_str->size + 1));
	if (st_str->str == NULL)
		return ;
	set_unsigned_number_base(st_str->str, num, base);
}
