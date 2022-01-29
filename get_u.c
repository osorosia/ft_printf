/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 07:38:27 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/29 17:51:49 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_u(va_list ap, t_str *st_str)
{
	unsigned int	num;
	const char		*base = "0123456789";
	const int		base_size = 10;

	num = va_arg(ap, unsigned int);
	st_str->size = ft_numlen_base(num, base_size);
	st_str->str = (char *)malloc(sizeof(char) * (st_str->size + 1));
	if (st_str->str == NULL)
		return ;
	set_unsigned_number_base(st_str->str, num, base);
}
