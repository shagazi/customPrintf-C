/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:19:07 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/03 15:12:40 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*convert_int_toalpha(void *p, t_struct *fmt)
{
	char	f;
	char	*str;
	int		*test;

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

int		bytelen(t_struct *fmt)
{
	int i;

	i = 0;
	if (fmt->formatstr != NULL)
	{
		if (fmt->width > FMTLEN(fmt))
			i = fmt->width;
		else if (fmt->width <= FMTLEN(fmt) && fmt->width >= 0)
			i = ft_strlen(fmt->formatstr);
		else if (fmt->negwidth < 0)
			i = (fmt->negwidth * -1);
	}
	else if (fmt->width > 1)
		i = fmt->width;
	else if (fmt->format == '\0')
		i = 0;
	else if (fmt->format == 'S')
		i = 0;
	else
		i = 1;
	return (i);
}
