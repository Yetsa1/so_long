/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:56:06 by yeparra-          #+#    #+#             */
/*   Updated: 2024/10/24 20:37:20 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *cs, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;

	s = cs;
	i = 0;
	while (i < n)
	{
		if (*s == (unsigned char)c)
		{
			return ((void *)s);
		}
		else
		{
			s++;
			i++;
		}
	}
	return (0);
}
