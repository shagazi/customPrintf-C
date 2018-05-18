/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 22:22:47 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/17 18:31:06 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <errno.h>
# include <wchar.h>
# include "../libft/libft.h"

typedef struct f_list{
	char *flags;
	int width;
	int presicion;
	int modifier;
	char format;
	int byte_len;
	void *formatstr;
	char formatchar;
	char *basenumber;
	char sign;
}fmt_list;

/************************* Length Specifiers *************************/
/************ MODIFICATION OF THE LENGTH OF THE DATA TYPE ************/
/*** hh == signed char (d, i) or unsigned char (u,o,x,X) ******************/
# define MOD_HH 1
/*** ll = long long int (d, i) or unsigned long long int (u,o,x,X) ***/
# define MOD_LL 2
/*** h = short int (d, i) or unsigned short int (u,o,x,X) ************/
# define MOD_H 3
/*** l = long int (d, i) or unsigned long int (u,o,x,X) **************/
# define MOD_L 4
/*** j = intmax_t (d, i) or usigned intmax_t (u,o,x,X) ***************/
# define MOD_J 5
/*** z = size_t (d, i, u, o, x, X) ***********************************/
# define MOD_Z 6

/*** Oct decimal system is a power of 8 ***/
# define OCT "01234567"
/*** Hex decimal system is a power of 16 ***/
# define HEX "0123456789abcdef"
# define HEXX "0123456789ABCDEF"

void 	getoutputhelp(fmt_list *fmt);
void 	getoutput(fmt_list *fmt, va_list *arg);
void 	printoutput(fmt_list *fmt);
int 	ft_printf(char *format, ...);

void 	callflags(fmt_list *fmt, int strlength);
void 	flagspace(fmt_list *fmt, int strlength);
void 	flagzero(fmt_list *fmt, int strlength);
void 	flaghex(fmt_list *fmt);
void 	flagplus(fmt_list *fmt);

char 	*signedcast(va_list *arg, fmt_list *fmt);
char 	*unsignedcast(va_list *arg, fmt_list *fmt);
void 	wchar_check(va_list *arg, fmt_list *fmt);
void 	char_check(fmt_list *fmt, va_list *arg);
void 	formatcheck(va_list *arg, fmt_list *fmt);

int 	parse_modifier(char *str, fmt_list *fmt);
int 	parse_precision(char *str, fmt_list *fmt, va_list *arg);
int 	parse_width(char *str, fmt_list *fmt, va_list *arg);
int 	parse_flags(char *str, fmt_list *fmt);
int 	parse_percent(char *str, fmt_list *fmt, va_list *arg);

char	*convert_int_toalpha(void *p, fmt_list *fmt);
int 	bytelen(fmt_list *fmt);

void 	presicionstring(fmt_list *fmt, int i);
void 	intpresicion(fmt_list *fmt);
void 	applypresicion(fmt_list *fmt);

#endif
