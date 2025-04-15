/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:20:32 by yeparra-          #+#    #+#             */
/*   Updated: 2023/10/26 23:34:01 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_pers(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && set_pers(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	while (end > start && set_pers(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start +1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
	char	*s1 = "\tHello, World! \t";
	char	*set = " \t";
	char	*result;

	result = ft_strtrim(s1, set);
	if (result == NULL)
		printf("La cadena es nula\n");
	else
	{
		printf("Cadena original: \"%s\"\n", s1);
		printf("Cadenas eliminando tab: \"%s\"\n", result);
		free(result);
	}
	return (0);
}*/