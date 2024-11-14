/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:29:36 by yeparra-          #+#    #+#             */
/*   Updated: 2023/10/05 12:56:27 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int letter)
{
	int	ascii;

	ascii = (int) letter;
	if (ascii >= 97 && ascii <= 122)
	{
		ascii = ascii -32;
		letter = (char) ascii;
		return (letter);
	}
	else
	{
		return (letter);
	}
}
/*
int	main()
{
	char	c = "m";
	int	result = ft_toupper(c);
	
	printf("Conversión a Mayúcula %c\n", result);

	return (0);
}*/