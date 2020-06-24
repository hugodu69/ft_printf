/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:16:20 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 14:29:46 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	create a new list
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
**	t_list	*ft_lstnew(void *content);
**
**	int	main(void)
**	{
**		char	tresor;
**		t_list	*toto;
**
**		tresor = 'd';
**		printf("tresor                : %c\n",tresor);
**		toto = ft_lstnew(&tresor);
**		//toto->content was alocated as void* so it need cast
**		printf("toto->content         : %c\n",*(char*)(toto->content));
**		tresor = 'D';
**		printf("transform tresor      : %c\n",tresor);
**		printf("and also toto->content: %c\n",*(char*)(toto->content));
**		return (0);
**	}
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*lst;

	if (!(lst = (t_list *)malloc(sizeof(*lst))))
		return (NULL);
	if (!content)
		lst->content = NULL;
	else
		lst->content = content;
	lst->next = NULL;
	return (lst);
}
