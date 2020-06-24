/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:12:02 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 14:36:54 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	add an element to the begining of a list
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
**	void	*ft_memcpy(void *dst, const void *src, size_t n)
**	{
**		size_t	i;
**		char	*ptr;
**		char	*ptr2;
**
**		ptr = (char *)dst;
**		ptr2 = (char *)src;
**		i = -1;
**		while (++i < n)
**			ptr[i] = ptr2[i];
**		return (dst);
**	}
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
**		{
**			if (!(lst->content = malloc(sizeof(content))))
**				return (NULL);
**			ft_memcpy(lst->content, content, sizeof(content));
**		}
**		lst->next = NULL;
**		return (lst);
**	}
**
**	void	ft_lstadd_front(t_list **alst, t_list *new);
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
**		ft_lstadd_front(&toto, tmp);
**		printf("----------------------\n");
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		tmp = ft_lstnew(&friends);
**		ft_lstadd_front(&toto, tmp);
**		printf("----------------------\n");
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		printf("toto->nxt->nxt->dqta:%c\n",*(char*)(toto->next->next->content));
**		return (0);
**	}
*/

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
