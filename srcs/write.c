/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:19:07 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/31 15:58:47 by shagazi          ###   ########.fr       */
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
		else if (fmt->width <= (int)ft_strlen(fmt->formatstr) && fmt->width >= 0)
			i = ft_strlen(fmt->formatstr);
		else if (fmt->negwidth < 0)
			i = (fmt->negwidth * -1);
	}
	else if (fmt->width > 1)
		i = fmt->width;
	else if (fmt->format == '\0')
		i = 0;
	else
		i = 1;
	return (i);
}
