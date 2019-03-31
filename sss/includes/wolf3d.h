/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:20:01 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/29 16:51:54 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# define BUFF_SIZE 111
# define SIZE 64

typedef struct		s_line
{
	int				x0;
	int				y0;
	int				clr0;
	int				x1;
	int				y1;
	int				clr1;
}					t_line;

typedef struct		s_val
{
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				error;
	int				error2;
}					t_val;

typedef struct		s_player
{
	int				x;
	int				y;
	float			angle;
}					t_player;

typedef struct 		s_mouse
{
	int				mouse_1;
	int				mouse_2;
	int				mouse_x;
	int				mouse_y;
}					t_mouse;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				end;
	int				x;
	int				y;
	char			**map;
	t_player		player;
	t_mouse			mouse;
}					t_mlx;



typedef struct		s_thredsct
{
	int				startx;
	int				maxx;
	t_mlx			*mlx;
}					t_thredsct;



int				ft_exit(t_mlx *mlx);
int				get_next_line(const int fd, char **line);
int				get_map(int fd, char ***map);
void			move_player(int key, t_mlx *mlx);
void			clear_image(t_mlx *mlx);
void			wolf_init(t_mlx *mlx);
void			wolf3d(t_mlx *mlx);
void			put_line(t_mlx *mlx, t_line line);
void			set_pxl(char *str, int x, int y, int clr);

#endif
