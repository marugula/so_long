/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:16:35 by marugula          #+#    #+#             */
/*   Updated: 2021/10/18 17:16:36 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*find;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	find = *lst;
	while (find->next != 0)
		find = find->next;
	find->next = new;
}
