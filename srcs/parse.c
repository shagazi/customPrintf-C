/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 22:48:00 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/31 23:46:41 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int parse_modifier(char *str, fmt_list *fmt)
{
	int i = 0;
	if(str[0] == 'h' && str[1] == 'h')
		fmt->modifier = MOD_HH;
	else if(str[0] == 'l' && str[1] == 'l')
		fmt->modifier = MOD_LL;
	else if(str[0] == 'h')
		fmt->modifier = MOD_H;
	else if(str[0] == 'l')
		fmt->modifier = MOD_L;
	else if(str[0] == 'j')
		fmt->modifier = MOD_J;
	else if(str[0] == 'z')
		fmt->modifier = MOD_Z;
	if(fmt->modifier == 1 || fmt->modifier == 2)
		i = 2;
	if(fmt->modifier >= 3 && fmt->modifier <= 6)
		i = 1;
	return (i);
}

int parse_precision(char *str, fmt_list *fmt, va_list *arg)
{
	int i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == '*')
		{
			i++;
			fmt->presicion = va_arg(*arg, int);
		}
		else
			fmt->presicion = ft_atoi(&str[1]);
		fmt->presicionflag = 1;
	}
	return (i);
}

int parse_width(char *str, fmt_list *fmt, va_list *arg)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '*')
	{
		i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			va_arg(*arg, int);
			fmt->width = ft_atoi(str + i);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else
			fmt->width = va_arg(*arg, int);
	}
	else
		fmt->width = ft_atoi(str);
	fmt->negwidth = fmt->width;
	return (i);
}

int parse_flags(char *str, fmt_list *fmt)
{
	int i;
	char *tmp;

	i = 0;
	while (str[i] == ' ' || str[i] == '-' || str[i] == '+' || str[i] == '0'
		|| str[i] == '#')
	i++;
	tmp = ft_strnew(i);
	ft_strncpy(tmp, str, i);
	fmt->flags = ft_removedup(tmp);
	free(tmp);
	return (i);
}

int parse_percent(char *str, fmt_list *fmt, va_list *arg)
{
	int i;

	i = 0;
	fmtassign(fmt);
	i += parse_flags(str, fmt);
	i += parse_width(str + i, fmt, arg);
	i += parse_precision(str + i, fmt, arg);
	i += parse_modifier(str + i, fmt);
	fmt->format = str[i];
	if (fmt->format == '\0')
		return (0);
	i++;
	getoutput(fmt, arg);
	if (fmt->flags)
		free(fmt->flags);
	return (i);
}
