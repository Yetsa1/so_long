/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <yeparra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:23:11 by yeparra-          #+#    #+#             */
/*   Updated: 2024/10/31 19:31:18 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}
/*
int	main()
{
	char	*str1 = "Hello,";
	char	*str2 = "World!";
	char	*result;

	result = ft_strjoin(str1, str2);
	if (result == NULL)
	{
		printf("Error: no se pudieron unir las cadenas\n");
	}
	else
	{
		printf("Concatenación de str1 y str2: %s\n", result);
		free(result);
	}
	return (0);
}*/