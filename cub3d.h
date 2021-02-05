/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:42:33 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 12:15:59 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include "get_next_line.h"
# define TWO_PI  6.28318530718
# define PI 3.14159265359
# define WALL_SIZE 64
# define FOV 1.0471975512
# define INT_MAX +2147483647
# define TRUE 1
# define FALSE 0
# define BLACK 0

typedef struct				s_d_map
{
	char					*g_checkr;
	long long int			weight;
	long long int			height;
	char					*path_no;
	char					*path_so;
	char					*path_we;
	char					*path_ea;
	char					*path_s;
	char					*lol_t;
	char					*chk;
	int						is_r;
	int						is_no;
	int						is_so;
	int						is_we;
	int						is_ea;
	int						is_s;
	int						is_f;
	int						is_c;
	int						fd;
	unsigned long long int	red_f;
	unsigned long long int	green_f;
	unsigned long long int	blue_f;
	unsigned long long int	red_c;
	unsigned long long int	green_c;
	unsigned long long int	blue_c;
	int						number;
	int						fasila;
	int						info_done;
	int						now;
	int						is_number;
	int						is;
	char					*string;
	char					**map;
	int						rows;
	int						cols;
	int						width_map;
	int						hieth_map;
	float					player_x;
	float					player_y;
	int						player_ck;
	char					*save_str;
	char					*save_wnea;
	unsigned long long int	len;
}							t_d_map;

typedef struct				s_norm
{
	int						textureofsetx;
	int						textureofsety;
	float					dpp;
	float					correct_destance;
	float					project;
	float					wallstriphight;
	float					walltop;
	float					wallbottom;
	int						y;
	int						distancefromtop;
	int						color;
}							t_noms;

typedef struct				s_norm_3d
{
	int						textureofsetx;
	int						textureofsety;
	float					dpp;
	float					correct_destance;
	float					project;
	float					wallstriphight;
	float					walltop;
	float					wallbottom;
	int						i;
	int						distancefromtop;
	float					distanceprojectplan;
	int						y;
	int						b;
	int						c;
}							t_3d;

typedef struct				s_t
{
	int						s;
}							t_t;

typedef struct				s_normsp
{
	float					dist;
	int						b;
}							t_n_sp;

typedef struct				s_sprit
{
	float					hitsprites_x;
	float					hitsprites_y;
	float					distance;
	float					distance_center;
	float					center_x;
	float					center_y;
	float					point_center_x;
	float					point_center_y;
	int						i;
	int						j;
	int						is_vertical;
	struct s_sprit			*next;
}							t_sprit;

typedef struct				s_ray
{
	float					rayangle;
	float					wallhitx;
	float					wallhity;
	float					distance;
	int						washitvertical;
	int						g_israyfacingup;
	int						g_israyfacingdown;
	int						g_israyfacingleft;
	int						israyfacingright;
	int						wallhitcontent;
	int						issprit;
	t_sprit					*sprit;
}							t_ray;

t_sprit						g_sprite;
t_ray						g_rays[3200];
t_d_map						g_map;
t_n_sp						g_n_sps;
t_noms						g_normi;
t_3d						g_3d;
t_sprit						*g_tmp;
t_sprit						*g_tmp2;
void						check_all(char *line);
int							ft_isdigit(char number);
int							ft_atoi(const char *str);
void						ft_putchar(char c);
void						test(void);
void						build_3d(void);
int							iswall(float x, float y);
int							is_sprit(float x, float y);
void						ft_putstr(char *str);
void						my_perror(char *str);
char						**ft_split(char const *str, char c);
char						*ft_strtrim(char const *s1, char const *set);
int							ft_strncmp(const char *s1, const char *s2,
							size_t n);
int							iswall_raycheck(float x, float y);
int							mlx_get_screen_size(void *mlx_ptr, int *sizex,
							int *sizey);
void						edit_sprit(int rayid, float x, float y,
							t_sprit *sprit);
void						render_sprites(float x, float y, int rayid);
void						helf_add_horisntal(float rayangle, int rayid);
void						helf_get_line(int nl, char *line);
void						start(int argc);
void						free_texture(void);
int							controller(void);
void						check_is_not_null(void);
void						check_is_not_null_v2(void);
char						*skip(char *str, char *str2);
void						check_space(char *line, int i);
void						render_w_s(int i);
void						push_string_v2(char *str);
void						horizntal(int rayid);
void						heflf_vertical(void);
void						vertical(int rayid);
void						complet_raycasting(int rayid);
int							moveplayer(int keycode);
float						normalizerayangle(float angle);
void						free_sprite(int i);
void						is_str(char *str, int is, int i, char *k);
void						castray(float rayangle, int rayid);
void						free_str_1(char **str, int o);
void						all_equal_zero(void);
void						zall_zero_global(void);
void						player_ey(void);
void						castallray(void);
void						turn(void);
void						walk(void);
void						texture(void);
void						walk_half(void);
char						*ft_strjoin1(char const *s1, char const *s2);
char						*ft_strjoin2(char *s1, char *s2);
int							check_str(char *lol, char *k);
void						check_new_line(char *str);
void						my_perror(char *str);
void						string_valid(void);
void						map_fall(void);
void						check_player(void);
void						is_valid(void);
void						add_string(char *line);
void						check_if_exists();
void						zall_zero_global(void);
void						map_check(void);
void						push_string(char *str);
void						skip_c_f(char *k, char *line);
void						is_map(char *line);
void						check_line_space(char *line);
void						check(char *str, int n_count, int o, char *line);
void						check_all(char *line);
int							len_of_line(char **str);
void						check_all_all(char *str, int n);
void						check_line_space(char *line);
void						now_or_not(void);
char						*ft_strcat(char *dest, char *src);
char						*ft_strcpy(char *dest, char *src);
void						check_space_f_l(char *line);
void						check_if_exists(void);
void						check_c(char *str, int n_count, char *line);
void						check_f(char *str, int n_count, char *line);
void						check_r(char *str1, int n_count, int o, char *line);
void						check_n_w_e_s(char *str, int n_count, int o,
							char *line);
void						helf_norm_no(char *line);
void						helf_norm_s(char *line);
void						helf_norm_ea(char *line);
void						helf_norm_so(char *line);
void						norm_we_helf(char *line);
void						ft_bzero(void *str, size_t n);
void						screen_shot(void);
float						distance_btween_point(float x1, float y1, float x2,
							float y2);
int							render_x_s_helf_1(t_sprit *sprit, int dest,
							int texetofsetx);
int							render_x_s_helf_2(t_sprit *sprit, int dest,
							int texetofsetx);
int							render_x_s_helf_3(t_sprit *sprit, int dest,
							int texetofsetx);
int							render_x_s_helf_4(t_sprit *sprit, int dest,
							int texetofsetx);
int							mini_add_2(int nl, char *argv[]);
int							redbutton(void);
t_sprit						*newsprit(void);
int							render_x_s(t_sprit *sprit, int i);
int							esc(int keycode);
void						installwindow(void);
void						draw_sprit(int i);
void						error_n();
int							g_fd;
void						*g_mlx;
void						*g_window;
void						*g_img;
int							*g_img_data;
int							g_bpp;
int							g_size_line;
int							g_endian;
int							g_turnface;
int							g_w_texture;
int							g_h_texture;
void						*g_texture_north;
void						*g_texture_south;
void						*g_texture_west;
void						*g_texture_east;
void						*g_texture_sprite;
int							*g_texture_north_img;
int							*g_texture_south_img;
int							*g_texture_east_img;
int							*g_texture_west_img;
int							*g_texture_sprite_img;
float						*g_destince_spt;
int							g_israyfacingup;
int							g_israyfacingdown;
int							g_israyfacinright;
int							g_israyfacingleft;
float						g_rayanglea;
float						g_xstep;
float						g_ystep;
float						g_xintercept;
float						g_yintercept;
float						g_horizntadestanse;
float						g_verticaldestanse;
float						g_newhorizantalx;
float						g_newhorizantaly;
int							g_foundhorizantalwallhit;
int							g_foundvertwallhit;
float						g_vertwallhitx;
float						g_vertwallhity;
float						g_newvertx;
float						g_newverty;
float						g_horizontalwallhitx;
float						g_horizontalwallhity;
int							g_wallhitx;
int							g_wallhity;
int							g_distance;
float						g_xtocheck;
float						g_ytocheck;
float						g_horhitsprites_x;
float						g_horhitsprites_y;
float						g_verthitsprites_x;
float						g_verthitsprites_y;
float						g_distanse_sprite;
int							g_i_s;
int							g_j_s;
int							g_center_x;
int							g_center_y;
float						g_xtocheckv;
float						g_ytocheckv;
int							g_is_vertical;
int							g_i;
int							g_ii;
int							g_fd;
int							g_xxxx;
int							g_max_r_x;
int							g_max_r_y;
char						*g_line;
char						g_player_what;
int							g_len_x;
int							g_len_y;
int							g_i_pla;
int							g_j_pl;
int							g_i_str;
int							g_save_is;
int							g_walkspeed;
int							g_turnderction;
int							g_walkderction;
float						g_turnspeed;
float						g_stopx;
float						g_stopy;
float						g_playerx;
float						g_playery;
float						g_a;
int							g_us1;
int							g_us2;
int							g_us3;
char						*g_check_1;
char						*g_check_2;

#endif
