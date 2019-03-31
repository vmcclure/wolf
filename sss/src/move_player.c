/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:05:26 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/29 11:48:18 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "stdio.h"/////////////////////////
static void	move_left(t_mlx *mlx)
{
  	mlx->player.x += 16 * cos(mlx->player.angle - (90 * M_PI / 180));
  	mlx->player.y += 16 * sin(mlx->player.angle - (90 * M_PI / 180));
  	if (mlx->map[mlx->player.y / SIZE][mlx->player.x / SIZE] != ' ' &&
            mlx->map[mlx->player.y / SIZE][mlx->player.x / SIZE] != 'p')
    {
        mlx->player.x -= 16 * cos(mlx->player.angle - (90 * M_PI / 180));
        mlx->player.y -= 16 * sin(mlx->player.angle - (90 * M_PI / 180));
    }
  	else
  	    wolf_init(mlx);
}

static void	move_back(t_mlx *mlx)
{
	mlx->player.x += 16 * cos(mlx->player.angle - (180 * M_PI / 180));
	mlx->player.y += 16 * sin(mlx->player.angle - (180 * M_PI / 180));
    if (mlx->map[mlx->player.y / SIZE][mlx->player.x / SIZE] != ' ' &&
        mlx->map[mlx->player.y / SIZE][mlx->player.x / SIZE] != 'p')
    {
        mlx->player.x -= 16 * cos(mlx->player.angle - (180 * M_PI / 180));
        mlx->player.y -= 16 * sin(mlx->player.angle - (180 * M_PI / 180));
    }
    else
        wolf_init(mlx);
}

static void	move_ahead(t_mlx *mlx)
{
	mlx->player.x += 16 * cos(mlx->player.angle);
	mlx->player.y += 16 * sin(mlx->player.angle);
    if (mlx->map[mlx->player.y / SIZE][mlx->player.x / SIZE] != ' ' &&
        mlx->map[mlx->player.y / SIZE][mlx->player.x / SIZE] != 'p')
    {
        mlx->player.x -= 16 * cos(mlx->player.angle);
        mlx->player.y -= 16 * sin(mlx->player.angle);
    }
    else
        wolf_init(mlx);
}

static void	move_right(t_mlx *mlx)
{
	mlx->player.x += 16 * cos(mlx->player.angle + (90 * M_PI / 180));
	mlx->player.y += 16 * sin(mlx->player.angle + (90 * M_PI / 180));
    if (mlx->map[mlx->player.y / SIZE][mlx->player.x / SIZE] != ' ' &&
        mlx->map[mlx->player.y / SIZE][mlx->player.x / SIZE] != 'p')
    {
        mlx->player.x -= 16 * cos(mlx->player.angle + (90 * M_PI / 180));
        mlx->player.y -= 16 * sin(mlx->player.angle + (90 * M_PI / 180));
    }
    else
        wolf_init(mlx);
}

void		move_player(int key, t_mlx *mlx)
{
	if (key == 0)
		move_left(mlx);
	if (key == 1)
		move_back(mlx);
	if (key == 13)
		move_ahead(mlx);
	if (key == 2)
		move_right(mlx);
}
