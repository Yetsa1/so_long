/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:57:34 by yeparra-          #+#    #+#             */
/*   Updated: 2023/11/05 15:16:43 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
/*
int	main()
{
	char	*s = "Hello, World!\n";
	int	fd = open("archivo.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);

	if (fd == -1)
	{
		printf("Error al abrir el archivo.\n");
		return (1);
	}
	ft_putstr_fd(s, fd);
	close(fd);
	return (0);
}*/