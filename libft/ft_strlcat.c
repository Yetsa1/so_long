/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:52:44 by yeparra-          #+#    #+#             */
/*   Updated: 2023/11/08 16:26:28 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s, const char *ct, size_t n)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = ft_strlen(s);
	if (n <= y)
		return (n + ft_strlen(ct));
	while (ct[x] != '\0' && y + 1 < n)
	{
		s[y] = ct[x];
		y++;
		x++;
	}
	s[y] = '\0';
	return (y + ft_strlen(&ct[x]));
}
