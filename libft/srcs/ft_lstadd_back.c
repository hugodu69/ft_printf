/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:11:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 14:36:12 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	add an element to the end of a list
**	or first if list has no element so far
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
**	void	ft_lstadd_back(t_list **alst, t_list *new);
**
**	int	main(void)
**	{
**		char	tresor;
**		char	matos;
**		char	friends;
**		t_list	*toto;
**		t_list	*tmp;
**
**		tresor = 'a';
**		matos = 'b';
**		friends = 'c';
**		toto = ft_lstnew(&tresor);
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		tmp = ft_lstnew(&matos);
**		ft_lstadd_back(&toto, tmp);
**		printf("----------------------\n");
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		tmp = ft_lstnew(&friends);
**		ft_lstadd_back(&toto, tmp);
**		printf("----------------------\n");
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		printf("toto->nxt->nxt->data:%c\n",*(char*)(toto->next->next->content));
**		printf("toto->nxt->nxt->nxt :%s\n",(char*)(toto->next->next->next));
**		return (0);
**	}
*/

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst)
	{
		tmp = *alst;
		if (!tmp)
			*alst = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		new->next = NULL;
	}
}
