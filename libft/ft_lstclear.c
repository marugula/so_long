/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:54:19 by marugula          #+#    #+#             */
/*   Updated: 2021/10/18 17:54:20 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*mem;

	while (*lst != 0)
	{
		mem = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = mem;
	}
}
