/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:39:45 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/29 22:25:21 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_error(t_str *st_str, t_flag *st_flag)
{
	ft_memset(st_str, 0, sizeof(t_str));
	ft_memset(st_flag, 0, sizeof(t_flag));
	st_str->str = ft_strdup("%");
	if (st_str->str == NULL)
		return ;
	st_str->size = 1;
	st_str->specifier = 'c';
}
