/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:22:50 by marugula          #+#    #+#             */
/*   Updated: 2021/10/18 18:22:52 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static t_list	*ft_lstfill(t_list *dst, t_list *src, void *(*f)(void *))
{
	t_list	*new;

	dst = ft_lstnew(src->content);
	dst->content = f(src->content);
	src = src->next;
	while (src != 0)
	{
		new = ft_lstnew(f(src->content));
		if (new == 0)
			return (0);
		ft_lstadd_back(&dst, new);
		src = src->next;
	}
	return (dst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rez;

	if (lst == 0)
		return (0);
	rez = 0;
	rez = ft_lstfill(rez, lst, f);
	if (rez == 0)
	{
		ft_lstclear(&rez, del);
		return (0);
	}
	return (rez);
}

/*int main()
{
	int tab[] = {0, 1, 2, 3};
	t_list *l = ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	t_list *m = ft_lstmap(l, addOne, free);
	for (int i = 0; i < 4; ++i)
	{
		printf("%p %p:    %d\n", m, m->next, *(int *)m->content);
		m = m->next;
	}
	freeList(l); ft_lstclear(&m, free);
}*/