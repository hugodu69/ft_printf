/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 17:05:53 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/25 18:48:55 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	#include <stdio.h>	//for printf
**	#include <fcntl.h>	//for open
**
**	int		main(int ac, char **av)
**	{
**		int		*fd;
**		int		i = 0;
**		int		j = 0;
**		int		ret;
**		char	*line = NULL;
**
**		fd = (int *)malloc(sizeof(int) * ac);
**		while (++i <= ac - 1)
**			fd[i - 1] = open(av[i], O_RDONLY);
**		i = 0;
**		while (j < ac - 1)
**		{
**			if ((ret = get_next_line(fd[i], &line)) > 0)
**			{
**				printf(" [fd%i-%i] %s\n", fd[i], ret, line);
**				free(line);
**				j = 0;
**			}
**			else if (ret == -1)
**			{
**				printf("[fd%i-%i] *ERROR*\n", fd[i], ret);
**				free(line);
**				j++;
**			}
**			else if (*line != '\0')
**				printf(" [fd%i-%i] %s\n", fd[i], ret, line);
**			else
**			{
**				printf("[fd%i-%i] %s *FINI*\n", fd[i], ret, line);
**				free(line);
**				j++;
**			}
**			i++;
**			if (i >= ac - 1)
**				i = 0;
**		}
**		free(fd);
**		//while (1);
**		return (0);
**	}
*/

int		free_lst(t_gnlist **lst, int ret)
{
	t_gnlist	*tmp;

	tmp = *lst;
	while (tmp->next != *lst)
		tmp = tmp->next;
	tmp->next = (*lst)->next;
	free((*lst)->str);
	if (*lst == (*lst)->next)
	{
		free(*lst);
		*lst = NULL;
	}
	else
	{
		free(*lst);
		*lst = tmp;
	}
	return (ret);
}

int		multi_fd(int fd, t_gnlist **lst)
{
	t_gnlist	*tmp;

	tmp = *lst;
	while (*lst && (*lst)->lfd != fd && (*lst)->next != tmp)
		*lst = (*lst)->next;
	if (!tmp || ((*lst)->next == tmp && (*lst)->lfd != fd))
	{
		if (!(tmp = (t_gnlist*)malloc(sizeof(*tmp))))
			return (0);
		tmp->lfd = fd;
		if (!(tmp->str = ft_strdup("")))
			return (0);
		if (*lst)
		{
			tmp->next = (*lst)->next;
			(*lst)->next = tmp;
		}
		else
			tmp->next = tmp;
		*lst = tmp;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char				buf[BUFFER_SIZE + 1];
	int					ret;
	static t_gnlist		*lst = NULL;
	char				*str;

	ret = 1;
	if (!(multi_fd(fd, &lst)) || !line || BUFFER_SIZE < 1)
		return (free_lst(&lst, -1));
	while (!(str = ft_strchr(lst->str, '\n')) && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (free_lst(&lst, -1));
		buf[ret] = '\0';
		if (!(lst->str = ft_strjoinfree(lst->str, buf)))
			return (free_lst(&lst, -1));
	}
	if (str != NULL)
		str[0] = '\0';
	if (!(*line = ft_strdup(lst->str)))
		return (free_lst(&lst, -1));
	if (str != NULL)
		return (ft_memmove(lst->str, str + 1, ft_strlen(str + 1) + 1) != NULL);
	return (free_lst(&lst, 0));
}
