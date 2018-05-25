/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:11:36 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/25 15:57:00 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strappend(char *s1, char *s2)
{
	int i;
	char *newstr;

	i = 0;
	if (!s1)
		newstr = ft_strdup(s2);
	else if (!s2)
		newstr = s1;
	else
		newstr = ft_strjoin(s1, s2);
	// newstr[ft_strlen(newstr)] = '\0';
	return (newstr);
}
