/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 07:14:55 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/10 18:30:02 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_d(va_list ap, t_str *st_str)
{
	int			num;
	const char	*base = "0123456789";

	num = va_arg(ap, int);
	if (num < 0)
		st_str->minus = true;
	st_str->size = ft_get_digit(ft_abs_ll(num), base);
	st_str->str = (char *)malloc(sizeof(char) * (st_str->size + 1));
	if (st_str->str == NULL)
		return ;
	set_number_base(st_str->str, ft_abs_ll(num), base);
}
