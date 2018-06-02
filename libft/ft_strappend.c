/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:11:36 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/02 13:55:54 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *s1, char *s2)
{
	int		i;
	char	*tmp;
	char	*tmptwo;

	i = 0;
	if (!s1)
	{
		tmptwo = s2;
		s1 = ft_strdup(s2);
		free(s2);
		return (s1);
	}
	else if (!s2)
		return (s1);
	else
	{
		tmp = s1;
		tmptwo = s2;
		s1 = ft_strjoin(s1, s2);
		free(tmptwo);
		free(tmp);
	}
	return (s1);
}
