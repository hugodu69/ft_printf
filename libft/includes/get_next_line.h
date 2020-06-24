/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 10:19:37 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/25 18:48:49 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct		s_gnlist
{
	int				lfd;
	char			*str;
	struct s_gnlist	*next;
}					t_gnlist;

int					get_next_line(const int fd, char **line);
int					multi_fd(int fd, t_gnlist **lst);
int					free_lst(t_gnlist **lst, int ret);

#endif
