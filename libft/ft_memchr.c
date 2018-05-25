/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:41:08 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/13 16:46:20 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	k;

	a = (unsigned char *)s;
	i = 0;
	k = c;
	while (i < n)
	{
		if (a[i] == k)
			return (&a[i]);
		i++;
	}
	return (NULL);
}
