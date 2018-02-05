/*
** write_char.c for 42sh in /home/hurlu/PSU_2015_42sh/src/line_edit
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sat Jun  4 14:21:12 2016 Hugo Willaume
** Last update Sun Jun  5 23:07:07 2016 Hugo Willaume
*/

#include	<unistd.h>
#include	<curses.h>
#include	<string.h>
#include	"misc.h"
#include	"line_edit.h"

static void	restore_position(t_tty *term, t_pos tmp_cur)
{
  int		width_idx;

  width_idx = 0;
  while (tmp_cur.x != term->cur_pos.x || tmp_cur.y != term->cur_pos.y)
    {
      if (tmp_cur.x == 0)
	{
	  tmp_cur.y--;
	  my_putstr(tigetstr("cuu1"));
	  while (width_idx < term->width)
	    {
	      my_putstr(tigetstr("cuf1"));
	      width_idx++;
	      tmp_cur.x++;
	    }
	  width_idx = 0;
	}
      else
	my_putchar('\b');
      tmp_cur.x--;
    }
  if (tmp_cur.x == term->width - 1)
    my_putchar('\n');
  else
    my_putstr(tigetstr("cuf1"));
}

void	write_char(char **result, int *idx, char c, t_tty *term)
{
  int		cpy_idx;
  t_pos		tmp_cur;
  char		buf;

  buf = 1;
  cpy_idx = (*idx);
  tmp_cur.x = term->cur_pos.x;
  tmp_cur.y = term->cur_pos.y;
  while (buf != 0)
    {
      if (tmp_cur.x == term->width)
	{
	  tmp_cur.x = 0;
	  tmp_cur.y++;
	}
      buf = (*result)[cpy_idx];
      (*result)[cpy_idx] = c;
      my_putchar(c);
      c = buf;
      tmp_cur.x++;
      cpy_idx++;
    }
  restore_position(term, tmp_cur);
}
