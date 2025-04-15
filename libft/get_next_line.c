/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:38:46 by yetsabe           #+#    #+#             */
/*   Updated: 2024/12/12 18:17:05 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *reserve)
{
	int			i;
	char		*str;

	i = 0;
	if (!reserve[i] || !reserve)
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		str[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		str[i] = reserve[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_reserve(char *reserve)
{
	int		i;
	char	*temp;
	char	*str;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	temp = reserve + i + 1;
	str = ft_strdup(temp);
	free (reserve);
	return (str);
}

char	*ft_read_and_reserve(int fd, char *reserve)
{
	int		readed;
	char	*buf;
	char	*new_reserve;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	while (!ft_strchr(reserve, '\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
			break ;
		buf[readed] = '\0';
		new_reserve = malloc(ft_strlen(reserve) + readed + 1);
		if (!new_reserve)
			break ;
		ft_memcpy(new_reserve, reserve, ft_strlen(reserve));
		ft_memcpy(new_reserve + ft_strlen(reserve), buf, readed + 1);
		free (reserve);
		reserve = new_reserve;
	}
	free (buf);
	return (reserve);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reserve;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(reserve);
		reserve = NULL;
		return (NULL);
	}
	reserve = ft_read_and_reserve(fd, reserve);
	if (!reserve)
	{
		free(reserve);
		return (NULL);
	}
	line = ft_get_line(reserve);
	reserve = ft_reserve(reserve);
	if (reserve != NULL)
	{
		free(reserve);
		reserve = NULL;
	}
	return (line);
}
