/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:35:30 by yeparra-          #+#    #+#             */
/*   Updated: 2024/09/09 21:01:35 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}
/*
int	main()
{
	char	s[12] = "Hola, Mundo";
	unsigned char	*result;

	printf("String original: %s\n", s);
	result = ft_memset(s, 'X', 5);
	printf("String modificada: %s\n", result);

	return (0);
}*/
