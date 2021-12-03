/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:03:44 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/02 04:51:19 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_c(va_list ap, t_str *st_str)
{
	st_str->str = (char *)malloc(sizeof(char) * 2);
	if (st_str->str == NULL)
		return ;
	st_str->size = 1;
	st_str->str[0] = (char)va_arg(ap, int);
	st_str->str[1] = '\0';
}
