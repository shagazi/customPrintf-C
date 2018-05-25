/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:36:07 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/16 23:38:27 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*b1;
	unsigned char	k;

	a1 = (unsigned char *)s1;
	b1 = (unsigned char *)s2;
	i = 0;
	k = c;
	while (i < n)
	{
		a1[i] = b1[i];
		if (b1[i] == k)
			return (&a1[i + 1]);
		i++;
	}
	return (0);
}
