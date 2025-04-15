/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:26:23 by yeparra-          #+#    #+#             */
/*   Updated: 2023/10/10 19:59:20 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*s, const void	*ct, size_t	n)
{
	char		*dst;
	const char	*src;
	size_t		i;

	if (!s && !ct)
		return (0);
	dst = (char *)s;
	src = (const char *)ct;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		++i;
	}
	return (s);
}
/*
int main()
{
	const char	*src = "Hello, World";
	char	dst[20];
	
	ft_memcpy(dst, src, 5);//copia los primer 5 bytes de src a dst.
	dst[n] = '\0';//agrega el terminador nulo al final de la cadena copiada
	printf("Contenido del destino: %s\n", dst);
	return (0);
}*/