/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 12:45:11 by ncoden            #+#    #+#             */
/*   Updated: 2015/09/02 16:02:04 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft-graphics/3denv.h"

int					**init_map(int fd);
t_3denv				*init_env(int **map);
void				init_events(t_3denv *env);

#endif
