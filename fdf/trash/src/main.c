/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 12:46:18 by ncoden            #+#    #+#             */
/*   Updated: 2015/09/02 16:01:26 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft-graphics/3denv.h"
#include "fdf.h"

int				main(int argc, char **argv)
{
	int			fd;
	int			**map;
	t_3denv		*env;

	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (!(map = init_map(fd)))
		return (0);
	if (!(env = init_env(map)))
		return (0);
	init_events(env);
	return (0);
}
