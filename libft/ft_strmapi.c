/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:37:18 by yeparra-          #+#    #+#             */
/*   Updated: 2023/10/28 11:15:26 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
/*
char	incrementa_ascii(unsigned int i, char c)
{
	return (c + 1);
}

int	main()
{
	char	*str = "Hello, World!";
	char	*result * ft_strmapi(str, incrementa_ascii);

	if (result != NULL)
	{
		Printf("Cadena original: \"%s\"\n", str);
		printf("Nueva cadena creada desde la función originl: \"%s\"\n", result);
		free(result);
	}
	else
	{
		printf("Error al aplicar ft_strmapo.\n");
	}
	return (0);
}*/