/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:14:49 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/28 16:43:18 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	return a pointer to the last element of a list
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
**	void	ft_lstadd_front(t_list **alst, t_list *new)
**	{
**		new->next = *alst;
**		*alst = new;
**	}
**
**	t_list	*ft_lstlast(t_list *lst);
**
**	int	main(void)
**	{
**		char	tresor;
**		t_list	*toto;
**		t_list	*tmp;
**
**		tresor = 'a';
**		toto = ft_lstnew(&tresor);
**		tresor = 'b';
**		tmp = ft_lstnew(&tresor);
**		ft_lstadd_front(&toto, tmp);
**		tresor = 'c';
**		tmp = ft_lstnew(&tresor);
**		ft_lstadd_front(&toto, tmp);
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		printf("toto->nxt->nxt->data:%c\n",*(char*)(toto->next->next->content));
**		tmp = ft_lstlast(toto);
**		printf("%c\n",*(char*)(tmp->content));
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		printf("toto->nxt->nxt->data:%c\n",*(char*)(toto->next->next->content));
**		return (0);
**	}
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
