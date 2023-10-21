/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulut <abulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:42:54 by abulut            #+#    #+#             */
/*   Updated: 2023/10/22 01:36:11 by abulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct l_index
{
	int	i;
	int	j;
	int	k;
}	t_index;

typedef struct l_start
{
	int		map_height;
	int		map_width;
	int		collectables;
	int		read_count;
	int		counter;
	int		y_axis;
	int		x_axis;

	char	**map;
	char	*maplocation;

	void	*mlxpointer;
	void	*winpointer;
	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	t_index	index;
}	t_game;

int		exit_point(t_game *data);
int		controls_working(int command, t_game *data);

void	gate_control(void);
void	player_control(void);
void	road_control(void);
void	sea_control(void);
void	worm_control(void);
void	err_msg(char *err);
void	ber_control(char *map_name);
void	wall_control(t_game *data);
void	map_control(char *map_name, t_game *data);
void	map_reading(t_game *data);
void	tmp_control(char *map_name);
void	map_processing(t_game *data);
void	images_in_game(t_game *data);
void	placeholder(t_game *data, int x, int y);
void	place_collectable(t_game *data, int height, int width);
void	place_player(t_game *data, int height, int width);
void	adding_in_graphics(t_game *data);
void	map_bug(t_game *data);

#endif
