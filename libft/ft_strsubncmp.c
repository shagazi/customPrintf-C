/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:33:23 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/17 00:35:48 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsubncmp(char *haystack, char *needle,
		unsigned int start, size_t len)
{
	int		i;
	char	*str;

	str = ft_strnew(len);
	i = 0;
	while (len--)
	{
		str[i] = haystack[start + i];
		i++;
	}
	while (*str != '\0' && *needle != '\0')
	{
		if (*str != *needle)
			return (*str - *needle);
		if (*str == '\0' && *needle == '\0')
			return (0);
		str++;
		needle++;
	}
	return (0);
}
