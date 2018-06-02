/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:27:29 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/02 13:51:35 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	i = 0;
	k = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		str[k++] = dest[i];
		i++;
	}
	while (src[j] != '\0')
	{
		str[k++] = src[j];
		j++;
	}
	str[k] = '\0';
	return (str);
}
