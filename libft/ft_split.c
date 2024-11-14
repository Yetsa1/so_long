/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <yeparra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:23:29 by yeparra-          #+#    #+#             */
/*   Updated: 2024/11/12 12:29:58 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_wds(char const *s, char c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			num++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (num);
}

static char	*two_wd(char const **src, char c)
{
	char	*start;
	char	*end;
	char	*wd;

	while (**src && **src == c)
		(*src)++;
	start = (char *)*src;
	while (**src && **src != c)
		(*src)++;
	end = (char *)*src;
	wd = ft_substr(start, 0, end - start);
	return (wd);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**wds;
	int		i;

	if (!s)
		return (NULL);
	count = num_wds(s, c);
	wds = (char **)malloc(sizeof(char *) * (count + 1));
	if (!wds)
		return (NULL);
	i = 0;
	while (i < count)
	{
		wds[i] = two_wd(&s, c);
		if (!wds[i])
		{
			while (i-- > 0)
				free(wds[i]);
			free(wds);
			return (NULL);
		}
		i++;
	}
	wds[i] = NULL;
	return (wds);
}
