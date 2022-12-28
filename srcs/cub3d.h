/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:00:58 by babkar            #+#    #+#             */
/*   Updated: 2022/12/28 21:04:46 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../utils/utils.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

# define ESC_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define GRID_SIZE 32
# define WIDTH 257
# define HEIGHT 257
# include <math.h>


typedef struct s_color
{
	int red;
	int green;
	int blue;
}t_color;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}t_mlx;

typedef	struct s_player
{
	int	x;
	int y;
	int	turn;
	int	walk;
	double	rotation_angle;
	double 	move_speed;
	double	rotation_speed;
}t_player;

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_color	floor;
	t_color	ceiling;
	t_mlx	mlx;
	t_player player;
	int		nbr_colums;
	int		nbr_lines;
	char	**map;
}t_map;

int	    parse_north_texture(char *texture, t_map *map);
int	    parse_south_texture(char *texture, t_map *map);
int	    parse_west_texture(char *texture, t_map *map);
int	    parse_east_texture(char *texture, t_map *map);
t_map	parse_identifiers(char *line, int fd, t_map map);


char	**read_map(char *line, char **map);
void	check_line(char *line, t_map *map);
void	parse_map(char **map_str, t_map *map);

int	    parse_color_floor(char *color, t_color *floor);
int	    parse_color_ceiling(char *color, t_color *ceiling);

int	    count_splited(char **str);
int     count_char(char *str, char c);
char    *skip_empty_line(char *line, int fd);
int	    empty_line(char *line);

t_map	parse(char **argv);

void	draw_line(t_map map, int beginX, int beginY, int endX, int endY, int color);


void    print_map(t_map map);
t_map player_init(t_map  map);
#endif