/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:28:24 by yeparra-          #+#    #+#             */
/*   Updated: 2023/11/04 23:03:32 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_digits(int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*result;
	unsigned int	i;

	len = ft_digits(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		i = -n;
	}
	else
		i = n;
	if (n == 0)
		result[0] = '0';
	result[len] = '\0';
	while (i != 0)
	{
		result[len -1] = '0' + (i % 10);
		i /= 10;
		len--;
	}
	return (result);
}
/*
int	main()
{
	int	num = -42;
	char	*result;

	result = ft_itoa(num);
	if (result != NULL)
	{
		printf("Entero original: %d\n", num);
		printf("Conversión de entero a cadena: \"%s\"\n", result);
		free();
	}
	else
	{
		printf("Error al convertir el entero a cadena.\n");
	}
	return (0);
}
*/