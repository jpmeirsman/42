/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 13:10:25 by ncoden            #+#    #+#             */
/*   Updated: 2015/08/30 18:52:53 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/basics/numbers.h"
#include "libft/containers/list.h"
#include "libft/utils/file.h"
#include "libft/utils/parse.h"

static inline int	map_line_count(char *line)
{
	int				count;

	count = 0;
	ft_prschr(&line, ' ');
	while (ft_skpnbr(&line))
	{
		ft_prschr(&line, ' ');
		count++;
	}
	return (count);
}

static inline void	map_line_fill(int *line_to, char *line_from)
{
	int				x;
	int				nbr;

	x = 0;
	ft_prschr(&line_from, ' ');
	while (ft_prsnbr(&line_from, &nbr))
	{
		line_to[x + 1] = nbr;
		ft_prschr(&line_from, ' ');
		x++;
	}
	line_to[0] = x;
}

int					**init_map(int fd)
{
	int				line_count;
	char			*line_from;
	int				*line_to;
	t_lst			*map;

	map = NULL;
	while (ft_readline(fd, &line_from))
	{
		line_count = map_line_count(line_from);
		if (!(line_to = (int *)malloc(sizeof(int) * (line_count + 1))))
			return (NULL);
		map_line_fill(line_to, line_from);
		ft_lstpushback(&map, line_to, sizeof(int) * (line_count + 1));
		free(line_from);
	}
	return (int **)ft_lsttoarray(map);
}
