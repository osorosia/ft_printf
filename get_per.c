/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_per.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 07:38:27 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 08:49:41 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_per(t_str *st_str)
{
	st_str->str = ft_strdup("%");
	if (st_str->str == NULL)
		return ;
	st_str->size = 1;
}
