/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:56:12 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/19 19:09:34 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		lenneedle;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	lenneedle = ft_strlen(needle);
	while (haystack[i] != '\0')
	{
		if (ft_strncmp((char *)&haystack[i], needle, lenneedle) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
