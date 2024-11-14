/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <yeparra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:18:47 by yeparra-          #+#    #+#             */
/*   Updated: 2024/11/12 12:28:58 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		x;
	int		y;
	char	*des;

	x = ft_strlen(s1);
	y = 0;
	des = (char *)malloc(sizeof(char) * (x + 1));
	if (des == NULL)
		return (0);
	while (s1[y] != '\0')
	{
		des[y] = s1[y];
		++y;
	}
	des[y] = '\0';
	return (des);
}
