/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_number_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:45:02 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 07:02:21 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_number_base(char *str, long long num, const char *base)
{
	size_t		str_len;
	long long	base_size;

	str_len = calc_number_of_digit(num, base);
	base_size = ft_strlen(base);
	str[str_len] = '\0';
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	while (str_len-- > 0 && num != 0)
	{
		str[str_len] = base[num % base_size];
		num /= base_size;
	}
}

void	set_unsigined_number_base(char *str, size_t num, const char *base)
{
	size_t	str_len;
	size_t	base_size;

	str_len = calc_unsigned_number_of_digit(num, base);
	base_size = ft_strlen(base);
	str[str_len] = '\0';
	while (str_len-- > 0 && num != 0)
	{
		str[str_len] = base[num % base_size];
		num /= base_size;
	}
}
