/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:38:33 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/29 21:12:54 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifdef DEBUG
void	debug_t_print(t_print *st)
{
	printf("t_print {\n");
	printf("    size : %lu\n", st->size);
	printf("    space: %lu\n", st->space);
	printf("    zero : %lu\n", st->zero);
	printf("    sign : %lu\n", st->sign);
	printf("    hex  : %lu\n", st->hex);
	printf("}\n");
}

void	debug_t_flag(t_flag *st)
{
	printf("t_flag {\n");
	printf("    width: %lu\n", st->width);
	printf("    prcs : %lu\n", st->precision);
	printf("    minus: %u\n", st->minus);
	printf("    zero : %u\n", st->zero);
	printf("    dot  : %u\n", st->dot);
	printf("    sharp: %u\n", st->sharp);
	printf("    space: %u\n", st->space);
	printf("    plus : %u\n", st->plus);
	printf("}\n");
}

void	debug_t_str(t_str *st)
{
	printf("t_str {\n");
	printf("    str	 : %s\n", st->str);
	printf("    size : %lu\n", st->size);
	printf("    minus: %u\n", st->minus);
	printf("    spec : %c\n", st->specifier);
	printf("}\n");
}
#endif
