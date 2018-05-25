/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 00:45:18 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/14 21:36:11 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	ch;
	int				i;
	int				counter;

	i = 0;
	ch = c;
	counter = ft_strlen(str);
	while (i <= counter)
	{
		if (str[counter] == ch)
			return ((char *)&str[counter]);
		counter--;
	}
	return (NULL);
}
