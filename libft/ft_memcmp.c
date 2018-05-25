/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 20:30:36 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/12 23:24:00 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*a1;
	const unsigned char		*b2;

	i = 0;
	a1 = s1;
	b2 = s2;
	while (i < n)
	{
		if (a1[i] != b2[i])
			return ((int)*(a1 + i) - (int)*(b2 + i));
		i++;
	}
	return (0);
}
