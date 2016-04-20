/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:18:47 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/20 18:37:04 by lleverge         ###   ########.fr       */
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

int					ft_init_term(t_term *termi);
int					ft_reset_term(t_term *termi);
int					myputchar(int c);
void				init_list(t_dblist *list);
t_dblist			*fill_list(char *str);
void				ft_add_link(t_term *termi, t_dblist *lst);
void				arg_in_list(char **argv, t_term *termi);
#endif
