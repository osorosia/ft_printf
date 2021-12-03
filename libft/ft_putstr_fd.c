/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:18:48 by rnishimo          #+#    #+#             */
/*   Updated: 2021/12/03 11:30:11 by rnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;
	size_t	buffer_size;

	if (s == NULL || fd < 0)
		return ;
	s_len = ft_strlen(s);
	buffer_size = INT_MAX / 2;
	while (s_len > buffer_size)
	{
		write(fd, s, buffer_size);
		s += buffer_size;
		s_len -= buffer_size;
	}
	write(fd, s, s_len);
}

void	ft_putnstr_fd(char *s, size_t n, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	write(fd, s, n);
}
