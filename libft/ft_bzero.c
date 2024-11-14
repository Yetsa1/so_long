/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:10:30 by yeparra-          #+#    #+#             */
/*   Updated: 2023/09/29 12:08:37 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	ft_memset(s, '\0', n);
}
/*
int	main()
{
	char	*s = "Hola, Mundo";

	printf("Antes: %s\n", s);
	ft_bzero(s, 5);
	printf("Después: %s\n, s");

	return (0);
}*/