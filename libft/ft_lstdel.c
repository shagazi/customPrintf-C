/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:04:04 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/19 17:23:32 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *next;

	current = *alst;
	if (del && alst)
	{
		while (current != '\0')
		{
			next = current->next;
			del(current->content, current->content_size);
			free(current);
			current = next;
		}
		*alst = NULL;
	}
}
