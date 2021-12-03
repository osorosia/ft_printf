/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 07:14:55 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 11:35:29 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	_abs(long long num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	get_d(va_list ap, t_str *st_str)
{
	int			num;
	const char	*base = "0123456789";

	num = va_arg(ap, int);
	if (num < 0)
		st_str->minus = true;
	st_str->size = calc_number_of_digit(_abs(num), base);
	st_str->str = (char *)malloc(sizeof(char) * (st_str->size + 1));
	if (st_str->str == NULL)
		return ;
	set_number_base(st_str->str, _abs(num), base);
}
