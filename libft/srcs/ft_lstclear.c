/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:13:30 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/28 17:06:48 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	delete and free an element of the list and all the followings
*/

/*
**	#include <libc.h>
**
**	typedef struct		s_list
**	{
**		void			*content;
**		struct s_list	*next;
**	}					t_list;
**
**	t_list	*ft_lstnew(void *content)
**	{
**		t_list		*lst;
**
**		if (!(lst = (t_list *)malloc(sizeof(*lst))))
**			return (NULL);
**		if (!content)
**			lst->content = NULL;
**		else
**			lst->content = content;
**		lst->next = NULL;
**		return (lst);
**	}
**
**	void	ft_lstadd_back(t_list **alst, t_list *new)
**	{
**		t_list	*tmp;
**
**		if (alst)
**		{
**			tmp = *alst;
**			if (!tmp)
**				*alst = new;
**			else
**			{
**				while (tmp->next)
**					tmp = tmp->next;
**				tmp->next = new;
**			}
**			new->next = NULL;
**		}
**	}
**
**	void	ft_delete(void *element)
**	{
**		*(char*)element = '\0';
**	}
**
**	void	ft_lstdelone(t_list *lst, void (*del)(void *))
**	{
**		del(lst->content);
**		free(lst);
**		lst = NULL;
**	}
**
**	void	ft_lstclear(t_list **lst, void (*del)(void *));
**
**	int	main(void)
**	{
**		t_list	*toto;
**		void	(ft_delete)(void*);
**
**		printf("sizeof(t_list)%lu\n",sizeof(t_list));
**		toto = ft_lstnew("a");
**		toto->next = ft_lstnew("b");
**		toto->next->next = ft_lstnew("c");
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		printf("toto->nxt->nxt->data:%c\n",*(char*)(toto->next->next->content));
**		printf("toto->nxt->nxt->nxt :%s\n",(char*)(toto->next->next->next));
**		ft_lstclear(&(toto->next), ft_delete);
**		printf("----------------------\n");
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		printf("toto->nxt->nxt      :%s\n",(char*)(toto->next->next));
**		return (0);
**	}
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
