/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:17:48 by yeparra-          #+#    #+#             */
/*   Updated: 2024/10/24 20:29:00 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int alpha_digit)
{
	if (alpha_digit >= 48 && alpha_digit <= 57)
		return (1);
	if (alpha_digit >= 65 && alpha_digit <= 90)
		return (1);
	if (alpha_digit >= 97 && alpha_digit <= 122)
		return (1);
	return (0);
}
