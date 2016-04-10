/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 16:43:29 by ncoden            #+#    #+#             */
/*   Updated: 2015/09/02 16:01:45 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/basics/booleans.h"
#include "libft-graphics/3denv.h"

static inline t_3dline	*env_create_line(t_3denv *env)
{
	t_3dline		*line;

	if (!(line = (t_3dline *)malloc(sizeof(t_3dline))))
		return (NULL);
	if (!(ft_3denvpush(env, line)))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static inline t_bool	env_fill_pos(t_3denv *env, int **map, int x, int y)
{
	t_3dline		*line;

	if (x < map[y][0])
	{
		if (!(line = env_create_line(env)))
			return (FALSE);
		ft_3dposset(&line->from, x * 20, y * 20, map[y][x]);
		ft_3dposset(&line->to, (x + 1) * 20, y * 20, map[y][x + 1]);
		line->color = 0xFFFFFF;
	}
	if (map[y + 1])
	{
		if (!(line = env_create_line(env)))
			return (FALSE);
		ft_3dposset(&line->from, x * 20, y * 20, map[y][x]);
		ft_3dposset(&line->to, x * 20, (y + 1) * 20, map[y + 1][x]);
		line->color = 0xFFFFFF;
	}
	return (TRUE);
}

static inline t_bool	env_fill(t_3denv *env, int **map)
{
	int				y;
	int				x;

	y = 0;
	while (map[y] != NULL)
	{
		x = map[y][0];
		while (x > 0)
		{
			env_fill_pos(env, map, x, y);
			x--;
		}
		y++;
	}
	return (TRUE);
}

t_3denv					*init_env(int **map)
{
	t_3denv			*env;

	if (!(env = ft_3denvnew(NULL, 800, 800, "fdf")))
		return (NULL);
	env_fill(env, map);
	return (env);
}
