/*
** data.h for 42sh in /home/fortevg/rendu/PSU/PSU_2015_42sh
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on Wen Jun 1 10:32:25 2016 Gabriel Forteville
<<<<<<< HEAD
** Last update Thu Jun  9 13:13:33 2016 Anthony LECLERC
=======
** Last update Thu Jun  9 13:06:45 2016 Sylvain Chaugny
>>>>>>> 5e2ee06e949c95b70e9cd0b13531acb55589e591
*/

#ifndef			DATA_H_
# define		DATA_H_

# include		<termios.h>
# include		"line_edit.h"
# include		"history.h"
# include		"bool.h"

# define		MODE_TTY	(0)
# define	        MODE_TERMINAL	(1)

typedef	struct		s_data t_data;

typedef	struct		s_builtin
{
  char			*builtin;
  int			(*f)(t_data *, char **);
}			t_builtin;

typedef struct		s_terminals
{
  struct termios	term;
  struct termios	new_term;
  t_tty			tty;
}			t_terminals;

struct			s_data
{
  int			terminal_mode;
  int			iofd[2];
  char			**env;
  t_history		history;
  char			*cmd;
  char			**exec;
  int			exit_value;
  int			is_exited;
  t_builtin		builtins[6];
  t_terminals		terms;
};

t_bool			check_if_name_is_correct(char *);
void			free_shell(t_data *, t_terminals *, int);
int			init_shell(t_data *, t_terminals *, char **);
int			init_term(t_tty *, struct termios *, struct termios *);
void			init_cursor(t_tty *, int);
int			get_to_home(t_data *);
int			get_to_oldpwd(t_data *);
char			*get_path(char **);
void			init_builtins_structure(t_data *);
int			show_history(t_data *, char **);
int			show_history(t_data *, char **);
int			my_cd(t_data *, char **);
int			my_setenv(t_data *, char **);
int			my_unsetenv(t_data *, char **);
int			echo(t_data *, char **);
t_bool			var_is(char *, char *);
int			my_exit(t_data *, char **);
char			*last_history(t_data *, char **);
char			*find_a_command(t_data *, char *);
int			clear_history(t_data *);
char			*cut_history(t_data *, char *);
int			my_modif_env(t_data *, char *, char *);
int			finish_history(t_data *);
void			free_hist(t_data *);

#endif			/* !DATA_H_ */
