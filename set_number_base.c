/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_number_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:45:02 by rnishimo          #+#    #+#             */
/*   Updated: 2022/01/29 19:59:16 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_number_base(char *str, long long num, const char *base)
{
	size_t		str_len;
	long long	base_size;

	base_size = ft_strlen(base);
	str_len = ft_numlen_base(num, base_size);
	str[str_len] = '\0';
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	if (num == 0)
		str[0] = base[0];
	while (str_len-- > 0 && num != 0)
	{
		str[str_len] = base[num % base_size];
		num /= base_size;
	}
}

void	set_unsigned_number_base(char *str, size_t num, const char *base)
{
	size_t	str_len;
	size_t	base_size;

	base_size = ft_strlen(base);
	str_len = ft_numlen_u_base(num, base_size);
	str[str_len] = '\0';
	if (num == 0)
		str[0] = base[0];
	while (str_len-- > 0 && num != 0)
	{
		str[str_len] = base[num % base_size];
		num /= base_size;
	}
}
