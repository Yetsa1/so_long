/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:28:04 by yeparra-          #+#    #+#             */
/*   Updated: 2024/09/09 20:52:56 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int number_received)
{
	if (number_received >= 'A' && number_received <= 'Z')
		return (1);
	if (number_received >= 'a' && number_received <= 'z')
		return (1);
	return (0);
}
/*
int	main()
{
	char	c = 'A';
	
	if (ft_isalpha (c))
		printf("%c 1 \n", c);
	else
		printf("%c 0 \n", c);

	return (0);
}*/
