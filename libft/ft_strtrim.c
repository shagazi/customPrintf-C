/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:21 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/19 18:25:40 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_vars(int *a, int *b, int *c, char **str)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*str = NULL;
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	init_vars(&i, &j, &k, &str);
	if (!s)
		return (NULL);
	k = s[k] == '\0' ? 0 : ft_spacecheck((char *)s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (k <= i)
		str = ft_strnew(0);
	else if (!(str = ft_strnew(k - i + 1)))
		return (NULL);
	while (i <= k)
	{
		str[j] = s[i];
		i += (j += 1) ? 1 : 1;
	}
	return (str);
}
