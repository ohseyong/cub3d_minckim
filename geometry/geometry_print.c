/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:06:58 by minckim           #+#    #+#             */
/*   Updated: 2020/07/14 00:06:59 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "../libft/libft.h"

void	face_print(t_face *f)
{
	if (f->type == TRIANGLE)
		ft_printf("%10s", "Triangle\n");
	else if (f->type == RECTANGLE)
		ft_printf("%10s", "Rectangle\n");
	vec_print(&(f->a));
	vec_print(&(f->b));
	vec_print(&(f->c));
}
