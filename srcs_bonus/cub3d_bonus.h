/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:49:13 by minckim           #+#    #+#             */
/*   Updated: 2020/07/20 13:29:52 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <pthread.h>
# include "../screen/screen.h"
# include "../libft/libft.h"
# include "key.h"
# define IMG_SPECIFIER "R EA NO WE SO F C AP 42 AN LB CR ST"
# define N_IMG 13
# define TYPE_FLOOR 0
# define TYPE_WALL 1
# define TYPE_SPRITE_AP 2
# define TYPE_SPRITE_42 3
# define TYPE_SPRITE_AN 4
# define RESOLUTION 0
# define IMG_EAST 1
# define IMG_NORTH 2
# define IMG_WEST 3
# define IMG_SOUTH 4
# define IMG_FLOOR 5
# define IMG_CEILLING 6
# define IMG_SPRITE_AP 7
# define IMG_SPRITE_42 8
# define IMG_SPRITE_AN 9
# define IMG_LIFEBAR 10
# define IMG_CROUCH 11
# define IMG_STAND 12
# define CEILLING_HEIGHT 4000
# define WALL_WIDTH 3000
# define EYE_LEVEL 1700
# define CUB_CAM_ANGLE M_PI_2
# define ANGLE_UNIT 0.05235987756
# define MOVE_WALK 300
# define MOVE_RUN 1000
# define JUMP_HEIGHT 1000
# define JUMP_DUL 1
# define TIME_SEGMENT 0.001
# define LIFE_MAX 100

typedef struct	s_player{
	t_vec		origin;
	t_angle		h;
	t_angle		v;
	int			run;
	int			jump;
	int			crouch;
	int			life;
}				t_player;

typedef struct	s_gamedata{
	int			n_entity;
	int			n_sprite_ap;
	int			n_sprite_42;
	int			n_sprite_an;
	int			n_item;
	int			size_x;
	int			size_y;
	t_bitmap	*texture[N_IMG];
	int			color[2];
	long long	keys[6];
	t_entity	floor;
	t_entity	wall;
	t_entity	sprite_ap;
	t_entity	sprite_42;
	t_entity	sprite_an;
	t_entity	non;
	t_entity	**entity;
	t_list		*lst_ent;
	t_list		*lst_item;
	t_entity	item[20];
	t_player	player;
	t_screen	screen;
}				t_gamedata;

/*
**	init.c---------------------------------------------------------------------
*/
void			check_arg_err(int argc, char **argv);
void			init_game_data(char *path, t_gamedata *g_data);

/*
**	init_check_map.c-----------------------------------------------------------
*/
int				check_map(char **map, t_gamedata *g_data);
/*
**	init_util.c----------------------------------------------------------------
*/
void			exit_message(char *err_massage, char *arg);
void			split_del(char **words);
int				lst_content_size(t_list *lst);
char			**lst_to_arr(t_list *lst);
/*
**	print_entities.c-----------------------------------------------------------
*/
void			print_entity_list(t_screen *s, t_list **lst_ent, int (*f)());
t_list			*entity_to_list(t_gamedata *g_data);
t_list			*item_to_list(t_gamedata *g_data);
void			print_entities(t_gamedata *g_data);
/*
**	mlx_put_fps.c--------------------------------------------------------------
*/
void			print_fps(clock_t fram_start, t_screen *s);
/*
**	init_create_entity.c-------------------------------------------------------
*/
t_entity		create_wall(t_bitmap **texture);
t_entity		create_floor_ceilling(t_bitmap **texture);
t_entity		create_sprite(t_bitmap **texture, int type);
t_entity		create_non(void);
/*
**	init_entity.c--------------------------------------------------------------
*/
void			init_entity(t_gamedata *g_data, char **map_arr);
/*
**	init_pars_line.c-----------------------------------------------------------
*/
void			parse_map(char *line, t_list **map);
int				parse_info(t_gamedata *g_data, char *line);

/*
**	player_manage.c------------------------------------------------------------
*/
void			player_turn(t_player *player, long long *key);
void			player_move(t_gamedata *g_data, long long *key);
void			player_fly(t_player *player, long long *key);
/*
**	check_collision.c----------------------------------------------------------
*/
int				check_collision(t_gamedata *g_data, t_vec *m);
/*
**	jump.c---------------------------------------------------------------------
*/
void			player_jump(t_player *p);
void			player_catch_jump(t_player *p, long long *keys);
/*
**	crouch.c-------------------------------------------------------------------
*/
void			player_crouch(t_player *p);
void			player_catch_crouch(t_player *p, long long *keys);
/*
**	mouse_motion.c-------------------------------------------------------------
*/
int				mouse_motion(int a, int b, t_gamedata *g_data);
/*
**	key_manager.c--------------------------------------------------------------
*/
int				key_press_manager(int key, long long *keys);
int				key_release_manager(int key, long long *keys);
int				is_pressed(int key, long long *keys);
int				mouse_press(int button, int x, int y, t_gamedata *g_data);
/*
**	hud.c------------------------------------------------------------
*/
void			screen_hud(t_screen *s, t_gamedata *g_data);
/*
**	hud_lifebar.c------------------------------------------------------------
*/
void			screen_lifebar(t_screen *s, t_bitmap *b, t_player *p);
/*
**	hud_stand_crouch.c---------------------------------------------------------
*/
void			screen_stand_crouch(t_screen *s, t_gamedata *g_data);
#endif
