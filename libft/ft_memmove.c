/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:33:49 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/16 23:32:26 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*a1;
	char	*b1;

	a1 = (char*)s1;
	b1 = (char*)s2;
	if (b1 < a1)
	{
		while (n--)
			a1[n] = b1[n];
	}
	else
		ft_memcpy(a1, b1, n);
	return (a1);
}
