/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:32:05 by yeparra-          #+#    #+#             */
/*   Updated: 2024/10/24 20:42:17 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int ascii)
{
	if (ascii >= 0 && ascii <= 127)
		return (1);
	return (0);
}
