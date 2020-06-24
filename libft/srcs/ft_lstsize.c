/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:31:48 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 16:06:41 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	return the size of the linked list
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
**	void	ft_lstadd_front(t_list **alst, t_list *new)
**	{
**		new->next = *alst;
**		*alst = new;
**	}
**
**	int		ft_lstsize(t_list *lst);
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
**		printf("toto->nxt->nxt->dqta:%c\n",*(char*)(toto->next->next->content));
**		printf("%i\n",ft_lstsize(toto));
**		printf("toto->data          :%c\n",*(char*)(toto->content));
**		printf("toto->nxt->data     :%c\n",*(char*)(toto->next->content));
**		printf("toto->nxt->nxt->dqta:%c\n",*(char*)(toto->next->next->content));
**		return (0);
**	}
*/

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
