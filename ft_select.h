/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:18:47 by lleverge          #+#    #+#             */
/*   Updated: 2016/05/02 14:29:20 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <curses.h>
# define BUFFER *(unsigned int *)buffer
# define RED "[31m"
# define BLUE "[34m"
# define CYAN "[36m"
# define RESET "[39m"
# define GREEN "[32m"
# define YELLOW "[33m"
# define MAGENTA "[35m"
# define COL 1
# define LINE 0

typedef struct		s_dblist
{
	char			*value;
	int				select;
	int				line;
	struct s_dblist	*next;
	struct s_dblist	*prev;
	int				len;
}					t_dblist;

typedef enum		e_enum
{
	LEFT_KEY = 4479771,
	RIGHT_KEY = 4414235,
	UP_KEY = 4283163,
	DOWN_KEY = 4348699,
	ESC_KEY = 27,
	SPACE_KEY = 32,
	DEL_KEY = 127,
	RET_KEY = 10,
	SUP_KEY = 2117294875,
	HOME_KEY = 4741915,
	END_KEY = 4610843,
	PAGE_UP_KEY = 2117425947,
	PAGE_DOWN_KEY = 2117491483,
	TAB_KEY = 9,
	CRTL_A_KEY = 1,
}					t_enum;

typedef struct		s_term
{
	struct termios	term;
	char			*name_term;
	int				nb_col;
	int				nb_row;
	int				enter;
	int				count[2];
	char			**ret_tab;
	t_dblist		*dblist;
}					t_term;

void				ft_print(t_term *termi);
int					list_size(t_term *termi);
int					ft_op_display(t_term *termi, int i, int max);
int					strlenint(char *str);
int					max_col(t_term *termi, int max);
void				get_screen_size(t_term *termi);
int					max_size(t_term *termi);
void				ft_signal(void);
void				manage_signal(int i);
void				ft_clear(void);
void				deselectall(t_term *termi);
void				selectall(t_term *termi);
void				ft_ret(t_term *termi);
void				stock_res(t_term *termi);
void				print_res(t_term *termi);
void				print_list(t_term *termi);
void				ft_manage_select(t_dblist *dblist);
void				select_underline(char *str);
void				print_select(char *str);
void				ft_underline(char *str);
int					ft_keyspot(t_term *termi);
void				ft_tab(t_term *termi);
int					ft_delete(t_term *termi);
void				ft_space(t_term *termi);
void				go_end(t_term *termi);
void				go_start(t_term *termi);
void				display_dblist(t_term *termi);
int					ft_init_term(t_term *termi);
int					ft_reset_term(t_term *termi);
int					myputchar(int c);
void				init_list(t_dblist *list);
t_dblist			*fill_list(char *str);
void				ft_add_link(t_term *termi, t_dblist *lst);
void				arg_in_list(char **argv, t_term *termi);
void				count_col(t_term *termi);
int					check_size(t_term *termi);
void				ft_resize(void);
t_term				*ft_stock(t_term *termi, int i);
#endif
