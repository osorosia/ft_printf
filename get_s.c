/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:02:06 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 07:33:30 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_s(va_list ap, t_str *st_str)
{
	char	*str;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	st_str->str = ft_strdup(str);
	if (st_str->str == NULL)
		return ;
	st_str->size = ft_strlen(st_str->str);
}
