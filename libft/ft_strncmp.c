/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:38:15 by yeparra-          #+#    #+#             */
/*   Updated: 2023/10/10 22:18:29 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s, const char *t, size_t n)
{
	while (n > 0 && (*s || *t))
	{
		if (*s != *t)
		{
			return ((unsigned char)*s - (unsigned char)*t);
		}
		s++;
		t++;
		n--;
	}
	return (0);
}
/*
int	main()
{
	char	*s1 = "abcd";
	char	*s2 = "abf";
	size_t	n = 4;
	int	cmp = ft_strncmp(s1, s2, n);

	if (cmp < 0)
		printf("s1 < s2\n");
	else if(resultado > 0)
	{
		printf("s1 es menor que s2\n");
	}
	else if (cmp > 0)
	{
		printf("s1 es mayor que s2\n");
	}
	else ("s1 y s2 con iguales hasta los primeros %zu carácteres\n")
	return (0);
}*/