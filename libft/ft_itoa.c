/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 00:59:42 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/15 01:01:25 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countplace(int tmp)
{
	int count;

	count = 0;
	while (tmp != 0)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

static char		*ft_itoaconvert(int count, int n, char *num)
{
	while (n != 0)
	{
		count--;
		num[count] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

char			*ft_itoa(int n)
{
	int		isneg;
	char	*num;
	int		tmp;
	int		count;

	tmp = n;
	isneg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	count = ft_countplace(tmp);
	if (n < 0)
	{
		isneg = 1;
		if (!(num = ft_strnew(count + isneg)))
			return (NULL);
		count = count + 1;
		n *= -1;
		num[0] = '-';
	}
	else if (!(num = ft_strnew(count + isneg)))
		return (NULL);
	num = ft_itoaconvert(count, n, num);
	return (num);
}
