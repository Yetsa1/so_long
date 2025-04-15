/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:00:04 by yeparra-          #+#    #+#             */
/*   Updated: 2023/09/29 12:59:29 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *cs, const void *ct, size_t n)
{
	const unsigned char	*ucs;
	const unsigned char	*uct;
	size_t				i;

	ucs = cs;
	uct = ct;
	i = 0;
	while (i < n)
	{
		if (ucs[i] != uct[i])
		{
			return (ucs[i] - uct[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	s1[] = "hello";
	char	s2[] = "hellx";
	size_t	n = 4;
	int	cmp = ft_memcmp(s1, s2, n);

	if(cmp < 0)
	{
		printf("Las primeras '%zu' bytes de s1 son menores que las de s2.\n", n);
	}
	else if(cmp > 0)
	{
		printf("Las primeras '%zu' bytes de s1 son mayores que las de s2.\n", n);
	}
	else
	{
		printf("Las primeras '%zu' bytes de s1 y s2 son iguales.\n", n);
	}
	return (0);
}*/