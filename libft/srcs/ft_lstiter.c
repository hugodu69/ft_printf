/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:14:11 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/01 16:03:40 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	go through all elements of the list and apply the function f to each of them
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
**	void	ft_lstiter(t_list *lst, void (*f)(void*));
**
**	void	to_uppercase(void *element)
**	{
**		//	*(char*)(((t_list*)element)->content) -= 32;
**		//	or :
**		t_list	*tmp;
**
**		tmp = (t_list*)element;
**		*(char*)(tmp->content) -= 32;
**	}
**
**	int	main(void)
**	{
**		t_list	*toto;
**		void	to_uppercase(void*);
**
**		toto = ft_lstnew("a");
**		toto->next = ft_lstnew("b");
**		toto->next->next = ft_lstnew("c");
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		printf("toto->nxt->nxt->data:%c\n",*(char*)(toto->next->next->content));
**		printf("toto->nxt->nxt->nxt :%s\n",(char*)(toto->next->next->next));
**		printf("---------------------------\n");
**		ft_lstiter(toto, to_uppercase);
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		printf("toto->nxt->nxt->data:%c\n",*(char*)(toto->next->next->content));
**		printf("toto->nxt->nxt->nxt :%s\n",(char*)(toto->next->next->next));
**		return (0);
**	}
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
