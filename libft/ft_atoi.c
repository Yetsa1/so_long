/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:31:45 by yeparra-          #+#    #+#             */
/*   Updated: 2023/11/08 15:21:00 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	n;
	int	sign;

	sign = 1;
	i = 0;
	n = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (s[i] != '\0')
		{
			n = 10 * n + (s[i] - '0');
			++i;
		}
	}
	return (n * sign);
}
/*
int	main()
{
	const char	*str1 = "  12345";
	const char	*str2 = "-6789";
	const char	*str3 = "42abc";

	int	num1 = ft_atoi(str1);
	int	num2 = ft_atoi(str2);
	int	num3 = ft_atoi(str3);

	printf("Resultado 1: %d\n", num1);
	printf("Resultado 2: %d\n", num2);
	printf("Resultado 3: %d\n", num3);

	return (0);
}*/