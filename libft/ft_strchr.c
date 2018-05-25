/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 22:24:38 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/21 20:13:35 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;
	int				i;

	ch = c;
	i = 0;
	if (ch == '\0')
	{
		while (str[i] != '\0')
			i++;
		if (str[i] == '\0')
			return ((char *)&str[i]);
	}
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
