/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:02:06 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/02 06:11:18 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_s(va_list ap, t_str *st_str)
{
	st_str->str = va_arg(ap, char *);
	if (st_str->str == NULL)
	{
		st_str->str = ft_strdup("(null)");
		if (st_str->str == NULL)
			return ;
	}
	st_str->size = ft_strlen(st_str->str);
}
