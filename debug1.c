/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:38:33 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/29 21:03:32 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifndef DEBUG
void	debug_t_print(t_print *st)
{
	(void)st;
}

void	debug_t_flag(t_flag *st)
{
	(void)st;
}

void	debug_t_str(t_str *st)
{
	(void)st;
}
#endif
