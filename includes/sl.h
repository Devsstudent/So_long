/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sl.h                                               :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: odessein <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/06 20:04:44 by odessein		  #+#	#+#			 */
/*   Updated: 2022/06/10 22:38:55 by odessein         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef SL_H
# define SL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

# define ESCAPE 65307
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define MOV_SPEED 1
# define SHIP_U "img/ship_u.xpm"
# define SHIP_D "img/ship_d.xpm"
# define SHIP_L "img/ship_l.xpm"
# define SHIP_R "img/ship_r.xpm"
# define SHIP_U_L "img/ship_u_l.xpm"
# define SHIP_U_R "img/ship_u_r.xpm"
# define SHIP_D_L "img/ship_d_l.xpm"
# define SHIP_D_R "img/ship_d_r.xpm"
# define COINS "img/coins_anim.xpm"
# define BACK "img/windows.xpm"
# define BACKGROUND	"img/background.xpm"
# define EXIT "img/exit.xpm"
# define WALL "img/wall.xpm"
# define ENEMY "img/enemy.xpm"
# define NUMBER "img/number.xpm"

//Constant to center the map
typedef void	t_mlx;

typedef struct s_mlx_info{
	t_mlx	*mlx;
	t_mlx	*win;
}			t_mlx_info;

typedef struct s_postion{
	int		x;
	int		y;
}			t_pos;

typedef struct s_move{
	t_bool	left;
	t_bool	right;
	t_bool	up;
	t_bool	down;
}			t_move;

typedef struct s_imag{
	void	*wall;
	void	*ship_r;
	void	*ship_l;
	void	*ship_d;
	void	*ship_u;
	void	*ship_d_l;
	void	*ship_u_l;
	void	*ship_d_r;
	void	*ship_u_r;
	void	*coins;
	void	*background;
	void	*exit;
	void	*back;
	void	*enemy;
	void	*number;
}			t_imag;

typedef struct s_info{
	int			nb_coin;
	void		*render;
	char		**map;
	t_bool		loaded;
	t_bool		no_coin;
	t_mlx_info	mlx;
	t_pos		pos;
	t_move		key;
	t_imag		img;
	int			size;
	t_list		*list_e;
	t_list		*list_t;
	t_pos		center;
	t_bool		end;
	void		*ship;
	void		*coins;
	int			counter;
	t_bool		enemy;
	t_bool		finish;
}				t_info;

typedef struct s_check{
	int	start;
	int	exit;
	int	collec;
}		t_check;

/*----------------------------CORE--------------------------------------*/
t_bool	sl_game(t_info *game);
void	sl_init_game(t_info *game);
int		sl_hook_press(int keycode, t_info *game);
int		sl_hook_release(int keycode, t_info *game);
int		sl_close(t_info *game);
int		sl_hook(t_info *game);
void	sl_finish(t_info *game, char *output);
void	sl_lose(t_info *game, char *output);

/*----------------------------PARSING/CHECKMAP--------------------------*/
t_bool	sl_nb_line(char *av, int *nb);
t_bool	sl_check_ber(char *map_name);
char	**sl_parse(int ac, char **av, int *size_main);
t_bool	sl_check_arg(char **av, int ac);
void	sl_init_list_to_check(t_check *list_to_check);
void	sl_fill_list(char c, t_check *list);
t_bool	ft_check_line_wall(char *line);
void	sl_free_map(char **map, int size);
t_bool	sl_check_map(char **map, t_info *game, int size);
t_bool	ft_check_rectangle(char **map, int size);
t_bool	ft_check_wall(char **map, int size);
t_bool	sl_check_component(char **map, int size, t_check *list);

/*----------------------------MOVEMENT--------------------------------------*/

t_bool	sl_move_ship(t_info *game);
void	sl_check_coins(t_info *game);
void	sl_check_wall(t_info *game);
t_bool	sl_check_exit(t_info *game);
t_bool	sl_check_enemy(t_info *game);

/*----------------------------HITBOX--------------------------------------*/

void	sl_check_wall_direc(t_info *game, int x, int y);
void	sl_check_wall_direct1(t_info *game, int x, int y);
t_bool	sl_check_exit_direc(t_info *game, int x, int y);
t_bool	sl_check_exit_direct2(t_info *game, int x, int y);
void	sl_check_coins_direc(t_info *game, int x, int y);
t_bool	sl_check_enemy_direc(t_info *game, int x, int y);
t_bool	sl_check_enemy_direc2(t_info *game, int x, int y);

/*----------------------------DISPLAY--------------------------------------*/

void	sl_display_background(t_info *game);
void	sl_display_ship(t_info *game);
void	sl_load_initial(t_info *game, char c, int x, int y);
void	sl_animate_coins(t_info *game, t_pos cord);
void	sl_animate_exit(t_info *game, t_pos cord);
void	sl_enemy_animation(t_info *game, t_pos cord, int frame);
void	sl_animate_enemy(t_info *game, float i);
void	sl_display_enemy(t_info *game);
void	sl_display_counter(t_info *game);

/*----------------------------UTILS--------------------------------------*/
t_bool	sl_check_coins_number(t_info *game);
void	sl_setup_exit(t_info *game, int x, int y);
void	sl_backup_exit(t_info *game);
void	sl_setup_start(t_info *game, int x, int y);
void	sl_setup_enemy(t_info *game, int x, int y);
t_bool	sl_load_img(t_info *game);
t_bool	sl_load_ship(t_info *game);
void	sl_init_struct(t_info *game);
void	sl_mlx_put_img_to_img(void *dest, void *src, t_pos pos);
void	sl_mlx_put_img_to_anim(void *dest, void *src, t_pos pos_src);
void	sl_replace_enemy(t_info *game);
void	sl_diagonal(t_info *game);
void	sl_putnbr_img(long long nb, t_info *game, int size);
void	sl_write_counter(long long nb, t_info *game, int size);

#endif
