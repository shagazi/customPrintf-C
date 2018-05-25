/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:14:59 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/20 18:22:11 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		sizestr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	sizestr = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(fresh = ft_strnew(sizestr)))
		return (NULL);
	while (s1[j] != '\0')
		fresh[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		fresh[i++] = s2[j++];
	return (fresh);
}
