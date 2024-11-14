/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:51:53 by yeparra-          #+#    #+#             */
/*   Updated: 2023/10/10 20:01:54 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = (void *)malloc(count * size);
	if (size > 0 && count > ULONG_MAX / size)
		return (NULL);
	if (dst == NULL)
		return (NULL);
	ft_bzero (dst, count * size);
	return (dst);
}
/*
int	main(void)
{
	char	*str;
	size_t	size = 5;

	str = (char *)ft_calloc(sizeof(char));
	if (str == NULL);
		return (1);
	for (size_t i = 0; i < size; i++)
		printf("%c ", str[i]);
	free(str);
	return (0);
}*/