/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 16:05:13 by ncoden            #+#    #+#             */
/*   Updated: 2015/09/02 16:01:38 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft/basics/numbers.h"
#include "libft-graphics/3denv.h"

static int		event_loop(t_3denv *env)
{
	env->cam->ang.x += ft_degtorad(1);
	env->cam->ang.y += ft_degtorad(1);
	env->cam->ang.z += ft_degtorad(1);
	ft_3denvprint(env);
	return (1);
}

static int		event_key(int key, void *data)
{
	(void)data;
	if (key == 53)
		exit(0);
	return (1);
}

void			init_events(t_3denv *env)
{
	mlx_loop_hook(env->mlx, &event_loop, env);
	mlx_key_hook(env->win, &event_key, NULL);
	mlx_loop(env->mlx);
}
