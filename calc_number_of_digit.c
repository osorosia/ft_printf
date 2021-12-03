/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_number_of_digit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:45:02 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 08:58:34 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	calc_number_of_digit(long long num, const char *base)
{
	size_t	digit;
	size_t	base_size;

	base_size = ft_strlen(base);
	if (base_size == 0)
		return (0);
	digit = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		digit++;
	}
	while (num != 0)
	{
		num /= base_size;
		digit++;
	}
	return (digit);
}

size_t	calc_unsigned_number_of_digit(size_t num, const char *base)
{
	size_t	digit;
	size_t	base_size;

	base_size = ft_strlen(base);
	if (base_size == 0)
		return (0);
	if (num == 0)
		return (1);
	digit = 0;
	while (num != 0)
	{
		num /= base_size;
		digit++;
	}
	return (digit);
}
