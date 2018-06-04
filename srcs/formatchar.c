/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:44:26 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/03 21:45:29 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printcharhelp(t_struct *fmt)
{
	if (fmt->spaces != NULL || fmt->zeros != NULL)
	{
		fmt->formatstr = ft_strappend(fmt->spaces, fmt->formatstr);
		fmt->formatstr = ft_strappend(fmt->zeros, fmt->formatstr);
		if (fmt->negwidth < 0)
		{
			ft_putchar(fmt->formatchar);
			ft_putstr(fmt->formatstr);
		}
		else
		{
			ft_putstr(fmt->formatstr);
			ft_putchar(fmt->formatchar);
		}
	}
	else
		ft_putchar(fmt->formatchar);
}

void	printchar(t_struct *fmt)
{
	if (FLGNEG(fmt))
	{
		if (fmt->spaces != NULL)
		{
			fmt->formatstr = ft_strappend(fmt->formatstr, fmt->spaces);
			ft_putchar(fmt->formatchar);
			ft_putstr(fmt->formatstr);
		}
		else
			ft_putchar(fmt->formatchar);
	}
	else
		printcharhelp(fmt);
}

void	charflag(t_struct *fmt)
{
	if (fmt->width > 1)
	{
		if (ft_strchr(fmt->flags, '0'))
			flagzero(fmt, 1);
		else
			flagspace(fmt, 1);
	}
	if (fmt->width < 0)
		flagspace(fmt, 1);
	printchar(fmt);
}
