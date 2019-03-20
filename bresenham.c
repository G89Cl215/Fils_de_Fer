/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:05:07 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/20 23:26:49 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
//#include "fdf.h"
#include "window_manipulation.h"
#include "ft_printf.h"

/*
** Idee pour les points : faire une structure de 5 ints (liste chainees ?) avec
** les coordonnees x y z (resultant du parse dufichier d'entree) en absolu et
** les xpix, ypix qui correspondent aux oordonnees du pixel resultant de la
** vision en 2D du a l'ecrasement de la 3D par la vue actuelle.
*/

//mlx_pixel_put

void		ft_bresenham(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int		pixel[2];//les pixels que nous allons afficher a la volee.
	float	pente;//la pente de la droite de point1 vers point2
	float	err;//representel'approximation due au fait que l'on allume des pixels c'est a dire un quadrillage discret.
	int		cnt;
	int		i;

	i = 0;
	err = 0.0;
	pixel[0] = x1;
	pixel[1] = y1;
	if (x1 == x2)//si la droite est verticale, la colonne de pixel a allumer ne depend pas de x
	{
		cnt = (y2 - y1 > 0) ? y2 - y1 : y1 - y2;//on veut donc allumer ce nombre de pixels a x constant
		while (i++ < cnt)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, pixel[0], pixel[1], 215);
			pixel[1] += (y2 - y1 > 0) ? 1 : -1;
		}
	}
	else
	{
		pente = (float)(y2 - y1) / (float)(x2 - x1);//le premier if evite la division par 0
		pente *= (x2 > x1) ? 1: -1;
ft_printf(" pente : %f\n", pente);
		cnt = (x2 - x1 > 0) ? x2 - x1 : x1 - x2;//nombre de x differents traites
		while (i++ < cnt) //pour chaque x..
		{
			mlx_pixel_put(mlx_ptr, win_ptr, pixel[0], pixel[1], 215);
			err += pente;
			while ((err > 1.0) || (err < -1.0)) //...on traite en fonction de la pente le nombre de y a allumer
			{
				pixel[1] += (err > 0.0) ? 1 : -1;
				err += (err > 0.0) ? -1.0 : 1.0;
				mlx_pixel_put(mlx_ptr, win_ptr, pixel[0], pixel[1], 215);
			}
			pixel[0] += (x2 > x1) ? 1: -1;
		}
	}
	mlx_pixel_put(mlx_ptr, win_ptr, pixel[0], pixel[1], 215);
}

void 	affiche_struct(t_win *win, unsigned int width, unsigned int height)
{
	int				i;
	int				j;	

	i = 0;
	j = 0;
	ft_printf("%f, %f \n", win->def_x, win->def_y);
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			ft_printf("pixel[%i, %i] = [%i, %i]\n", i, j, (int)(win->def_x * win->pixel[i][j][0] + win->offset), (int)(win->def_y * win->pixel[i][j][1] +  win->offset));
			if (i + 1 != width)
			{
				ft_printf("pixel[%i, %i] = [%i, %i]\n", i, j, (int)(win->def_x * win->pixel[i+1][j][0] + win->offset), (int)(win->def_y * win->pixel[i+1][j][1] +  win->offset));
				ft_bresenham(win->mlx_ptr, win->id_ptr, (int)(win->def_x * win->pixel[i][j][0]) + win->offset - win->origin[0], (int)(win->def_y * win->pixel[i][j][1]) + win->offset - win->origin[1], (int)(win->def_x * win->pixel[i + 1][j][0]) + win->offset - win->origin[0], (int)(win->def_y * win->pixel[i + 1][j][1]) + win->offset - win->origin[1]);
			}
			if (j + 1 != height)
			{
				ft_printf("pixel[%i, %i] = [%i, %i]\n", i, j, (int)(win->def_x * win->pixel[i][j+1][0] + win->offset), (int)(win->def_y * win->pixel[i][j+1][1] +  win->offset));
				ft_bresenham(win->mlx_ptr, win->id_ptr, (int)(win->def_x * win->pixel[i][j][0]) + win->offset - win->origin[0], (int)(win->def_y * win->pixel[i][j][1]) + win->offset - win->origin[1], (int)(win->def_x * win->pixel[i][j + 1][0]) + win->offset - win->origin[0], (int)(win->def_y * win->pixel[i][j + 1][1]) + win->offset - win->origin[1]);
			}
				j++;
		}
		i++;
	}
}
/*
void 	affiche_quadrillage(unsigned int width, unsigned int height)
{
	void			*mlx_ptr;
	void			*win_ptr;
	float			deformation_x;
	float			deformation_y;
	int				i;
	int				j;	

	
	i = 0;
	j = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF_test");
	deformation_x = ft_distortion_size_x(width);
	deformation_y = ft_distortion_size_y(height);
	ft_printf("%f, %f \n", deformation_x, deformation_y);
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			if (i + 1 != width)
				ft_bresenham(mlx_ptr, win_ptr, i * deformation_x + win->offset, j * deformation_y + win->offset, (i + 1) * deformation_x + win->offset, j * deformation_y + win->offset);
			if (j + 1 != height)
				ft_bresenham(mlx_ptr, win_ptr, i * deformation_x + win->offset, j * deformation_y + win->offset, i * deformation_x + win->offset, (j + 1) * deformation_y + win->offset);
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
}
int		main()
{
	void			*mlx_ptr;
	void			*win_ptr;
	float			deformation_x;
	float			deformation_y;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF_test");
	ft_bresenham(mlx_ptr, win_ptr, 250,290,215,270);
	mlx_loop(mlx_ptr);
}*/
