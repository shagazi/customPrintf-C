/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:11:36 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/29 18:16:23 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strappend(char *s1, char *s2)
{
	int i;
	char *tmp;

	i = 0;
	tmp = s1;
	if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	else
		s1 = ft_strjoin(s1, s2);
	ft_strdel(&tmp);
	return (s1);
}
