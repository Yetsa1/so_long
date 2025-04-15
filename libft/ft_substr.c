/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:03:37 by yeparra-          #+#    #+#             */
/*   Updated: 2023/10/26 22:21:51 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	slen = ft_strlen((char *)s);
	if (!s)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	if (len == 0 || slen == 0)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	str = (char *)malloc(len +1);
	i = 0;
	if (!str)
		return (NULL);
	while (start < ft_strlen(s) && (i < len))
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
	char	*s = "Hello, World!";
	char	*str;
	unsigned int	start = 0;
	size_t	len = 5;

	str = ft_substr(s, start, len);
	printf("%s\n", str);
	free(str);

	return (0);
}*/