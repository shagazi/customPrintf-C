/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 22:22:47 by shagazi           #+#    #+#             */
/*   Updated: 2018/06/02 12:57:56 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <errno.h>
# include <wchar.h>
# include "../libft/libft.h"

typedef struct			s_struct{
	int					width;
	int					negwidth;
	int					presicion;
	int					presicionflag;
	int					modifier;
	int					byte_len;
	char				format;
	char				formatchar;
	wchar_t				*formatwstr;
	char				*basenumber;
	void				*formatstr;
	char				*sign;
	char				*flags;
	char				*hex;
	char				*zeros;
	char				*spaces;
}						t_struct;

# define MOD_HH			1
# define MOD_LL			2
# define MOD_H			3
# define MOD_L			4
# define MOD_J			5
# define MOD_Z			6

# define OCT 			"01234567"
# define HEX 			"0123456789abcdef"
# define HEXX 			"0123456789ABCDEF"

# define FMTLEN(fmt)	((int)ft_strlen((char *)fmt->formatstr))
# define HEXLEN(fmt)	(int)ft_strlen(fmt->hex)
# define ZEROLEN(fmt)	(int)ft_strlen(fmt->zeros)
# define SPACELEN(fmt)	(int)ft_strlen(fmt->spaces)
# define FLGZERO(fmt)	ft_strchr(fmt->flags, '0')
# define FLGNEG(fmt)	ft_strchr(fmt->flags, '-')
# define FLGPLUS(fmt)	ft_strchr(fmt->flags, '+')
# define FLGHASH(fmt)	ft_strchr(fmt->flags, '#')
# define FLGSPACE(fmt)	ft_strchr(fmt->flags, ' ')
# define FLGMINUS(fmt)	ft_strcmp(fmt->sign, "-")

void					fmtassign(t_struct *fmt);
void					formatadjust(t_struct *fmt);
void					getoutput(t_struct *fmt, va_list *arg);
int						sizeofstring(char *format, int i, t_struct *fmt,
						va_list *arg);
int						ft_printf(char *format, ...);

int						parse_modifier(char *str, t_struct *fmt);
int						parse_precision(char *str, t_struct *fmt, va_list *arg);
int						parse_width(char *str, t_struct *fmt, va_list *arg);
int						parse_flags(char *str, t_struct *fmt);
int						parse_percent(char *str, t_struct *fmt, va_list *arg);

void					flagspace(t_struct *fmt, int strlength);
void					flagzero(t_struct *fmt, int strlength);
void					flaghex(t_struct *fmt);
void					flagundef(t_struct *fmt);

char					*signedcast(va_list *arg, t_struct *fmt);
char					*unsignedcast(va_list *arg, t_struct *fmt);
void					wchar_check(va_list *arg, t_struct *fmt);
void					char_check(t_struct *fmt, va_list *arg);
void					formatcheck(va_list *arg, t_struct *fmt);

void					formatnegint(t_struct *fmt, char *str);
void					formatint(t_struct *fmt);
void					intflaghelp(t_struct *fmt);
void					intflag(t_struct *fmt);
void					castint(t_struct *fmt, va_list *arg);

void					nohashflag(t_struct *fmt);
void					formathex(t_struct *fmt);
void					hexflags(t_struct *fmt);

void					printchar(t_struct *fmt);
void					printwidestr(t_struct *fmt);
void					formatstr(t_struct *fmt);
void					strflag(t_struct *fmt);
void					charflag(t_struct *fmt);

void					presicionstring(t_struct *fmt, int i);
void					presicionzero(t_struct *fmt);
void					negpresicionzero(t_struct *fmt);
void					intpresicion(t_struct *fmt);
void					applypresicion(t_struct *fmt);

char					*convert_int_toalpha(void *p, t_struct *fmt);
int						bytelen(t_struct *fmt);

#endif
