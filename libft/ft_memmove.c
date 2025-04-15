/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:40:17 by yeparra-          #+#    #+#             */
/*   Updated: 2023/11/08 23:18:43 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s, const void *ct, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	dst = (unsigned char *)s;
	src = (unsigned char *)ct;
	i = 0;
	if ((dst == src) || (n == 0))
	{
		return (dst);
	}
	if (dst > src)
	{
		while (n-- > 0)
			dst[n] = src[n];
	}
	else
	{
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
/*
int	main()
{
	char	*str = "Hello, world";
	char	*src = str;
	char	*dst = src + 2;

	ft_memmove(dst, src, 13);
	printf("%s\n", str);
	return(0);
}*/