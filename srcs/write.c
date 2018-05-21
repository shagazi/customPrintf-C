/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:19:07 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/20 13:55:45 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*convert_int_toalpha(void *p, fmt_list *fmt)
{
	char	f;
	char	*str;
	int  *test;

	test = p;
	str = NULL;
	f = fmt->format;
	if (f == 'p')
		str = ft_ullitoa_tobase((unsigned long)p, HEX);
	else if (ft_strchr("oOuUxX", f))
		str = ft_ullitoa_tobase(*(unsigned long long int *)p, fmt->basenumber);
	else
		str = ft_llitoa_tobase(*(long long int *)p, fmt->basenumber);
	return (str);
}


int bytelen(fmt_list *fmt)
{
	int i;

	i = 0;
	if (fmt->formatstr != NULL)
	{
		if (fmt->width > (int)ft_strlen(fmt->formatstr))
			i = fmt->width;
		if (fmt->width <= (int)ft_strlen(fmt->formatstr))
			i = ft_strlen(fmt->formatstr);
	}
	else
	{
		if (fmt->width > 1)
			i = fmt->width;
		else
			i = 1;
	}
	return (i);
}
