/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:47:23 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/16 23:45:19 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	size_t	lenneedle;

	i = 0;
	j = 0;
	lenneedle = ft_strlen(needle);
	if (needle[i] == '\0')
		return ((char *)&haystack[i]);
	while (haystack[i] != '\0' && len >= lenneedle)
	{
		if (haystack[i] == needle[j])
		{
			if (ft_strsubncmp((char *)haystack,
						(char *)needle, i, lenneedle) == 0)
				return ((char*)&haystack[i]);
			else
				j = 0;
		}
		i++;
		len--;
	}
	return (NULL);
}
