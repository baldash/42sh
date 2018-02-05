/*
** line_edit.h for 42sh in /home/hurlu/tests/parody_shell
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Thu Jun  2 12:11:23 2016 Hugo Willaume
** Last update Thu Jun  9 13:14:24 2016 Anthony LECLERC
*/

#ifndef		LINE_EDIT_H_
# define	LINE_EDIT_H_

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_tty
{
  int		height;
  int		width;
  int		prompt_size;
  t_pos		cur_pos;
  char		*capacities[8];
}		t_tty;

typedef int	(*esc_func)(char **result, int *idx, char *escape_seq,
			    t_tty *term);

void		write_char(char **result, int *idx, char c, t_tty *term);
void		del_char(char *result, int *idx, t_tty *term);
int		word_left(char **result, int *idx, char *escape_seq,
			  t_tty *term);
int		word_right(char **result, int *idx, char *escape_seq,
			   t_tty *term);
int		start(char **result, int *idx, char *escape_seq, t_tty *term);
int		del(char **result, int *idx, char *escape_seq, t_tty *term);
int		kill_end(char **result, int *idx, char *escape_seq,
			 t_tty *term);
int		end(char **result, int *idx, char *escape_seq, t_tty *term);
int		go_left(char **result, int *idx, char *escape_seq,
			t_tty *term);
int		go_right(char **result, int *idx, char *escape_seq,
			 t_tty *term);
int		word_left(char **result, int *idx, char *escape_seq,
			  t_tty *term);
int		word_right(char **result, int *idx, char *escape_seq,
			   t_tty *term);
int		start(char **result, int *idx, char *escape_seq, t_tty *term);
int		end(char **result, int *idx, char *escape_seq, t_tty *term);
int		destroy_line(char **result, int *idx, char *escape_seq,
			     t_tty *term);
char		*line_edition(t_tty *);

#endif		/* LINE_EDIT_H */
