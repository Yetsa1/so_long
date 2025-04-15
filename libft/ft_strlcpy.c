/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 01:19:48 by yeparra-          #+#    #+#             */
/*   Updated: 2023/11/05 17:32:29 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s, const char *ct, size_t n)
{
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(ct);
	if (n > 0)
	{
		while (i < n - 1 && ct[i] != '\0')
		{
			s[i] = ct[i];
			i++;
		}
		s[i] = '\0';
	}
	return (len);
}
