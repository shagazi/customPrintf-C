/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:58:59 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/16 23:14:26 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	int		dstlen;
	size_t	dstsize;

	dstlen = 0;
	j = 0;
	dstsize = size;
	while (dstsize-- != 0 && dest[dstlen] != '\0')
		dstlen++;
	i = dstlen;
	dstsize = size - dstlen;
	if (dstsize != 0)
	{
		while (src[j] != '\0')
		{
			if (dstsize-- == 1)
				break ;
			dest[dstlen++] = src[j++];
		}
		dest[dstlen] = '\0';
	}
	return (i + ft_strlen(src));
}
