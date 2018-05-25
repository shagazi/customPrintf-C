/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:21:23 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/19 18:10:33 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**arr;

	i = 0;
	j = 0;
	count = ft_strcount(s, c);
	if (!s || !c)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(arr) * count + 2)))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < count && s[i])
	{
		arr[j] = ft_str(s, c, &i);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
