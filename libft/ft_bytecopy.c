/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytecopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:36:41 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/11 00:36:30 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bytecopy(void *s1, const void *s2, int i, int j)
{
	unsigned char			*a1;
	unsigned const char		*b1;
	int						k;
	int						h;

	a1 = s1;
	b1 = s2;
	k = 0;
	h = 0;
	while (k < i)
		k++;
	while (j != 0)
	{
		a1[h] = b1[k];
		j--;
		h++;
		k++;
	}
	a1[h] = '\0';
	return (a1);
}
