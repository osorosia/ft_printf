/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:28:06 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/10 18:39:36 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_get_digit(size_t num, const char *base)
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

size_t	ft_get_digit_ll(long long num, const char *base)
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
