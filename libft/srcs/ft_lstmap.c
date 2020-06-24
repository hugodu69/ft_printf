/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:15:42 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/01 16:02:13 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	iterate trhough linked list and apply to each element a function f
**	if necessary the function del is used to delete an element
*/

/*
**	#include <stdlib.h>
**	#include <unistd.h>
**	#include <stdio.h>
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
**	char	*ft_strdup(const char *src)
**	{
**		int		i;
**		char	*str;
**
**		i = 0;
**		while (src[i] != '\0')
**			i++;
**		if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
**			return (NULL);
**		while (i-- >= 0)
**			str[i + 1] = src[i + 1];
**		return (str);
**	}
**
**	void	*to_uppercase(void *element)
**	{
**		char	*i;
**
**		if (!(i = ft_strdup((char*)element)))
**			return (NULL);
**		*i -= 32;
**		return ((void *)i);
**	}
**
**	void	ft_delete(void *element)
**	{
**		*(char*)element = '\0';
**	}
**
**	t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
**
**	int	main(void)
**	{
**		t_list	*toto;
**		void	*(to_uppercase)(void *);
**		void	(ft_delete)(void*);
**
**		toto = ft_lstnew("aa");
**		toto->next = ft_lstnew("b");
**		toto->next->next = ft_lstnew("c");
**		printf("toto->data          :%s\n",(char*)(toto->content));
**		printf("toto->nxt->data     :%s\n",(char*)(toto->next->content));
**		printf("toto->nxt->nxt->data:%s\n",(char*)(toto->next->next->content));
**		printf("toto->nxt->nxt->nxt :%s\n",(char*)(toto->next->next->next));
**		toto = ft_lstmap(toto, to_uppercase, ft_delete);
**		printf("----------------------\n");
**		printf("toto->data          :%s\n",(char*)(toto->content));
**		printf("toto->nxt->data     :%s\n",(char*)(toto->next->content));
**		printf("toto->nxt->nxt->data:%s\n",(char*)(toto->next->next->content));
**		printf("toto->nxt->nxt->nxt :%s\n",(char*)(toto->next->next->next));
**		return (0);
**	}
*/

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*tmp;

	if (!lst)
		return (NULL);
	if (!(tmp = ft_lstnew(f(lst->content))))
	{
		del(tmp->content);
		free(tmp);
		return (NULL);
	}
	new = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = ft_lstnew(f(lst->content))))
		{
			del(tmp->next->content);
			free(tmp->next);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (new);
}
