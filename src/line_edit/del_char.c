/*
** del_char.c for 42sh  in /home/hurlu/PSU_2015_42sh/src/line_edit
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sat Jun  4 14:23:23 2016 Hugo Willaume
** Last update Sun Jun  5 23:05:20 2016 Hugo Willaume
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<curses.h>
#include	<string.h>
#include	"misc.h"
#include	"line_edit.h"

static void	restore_position(t_tty *term, t_pos *pos)
{
  int		width;

  while (term->cur_pos.x != pos->x || term->cur_pos.y != pos->y)
    {
      if (--pos->x < 0)
    	{
    	  width = 0;
    	  my_putstr(tigetstr("cuu1"));
    	  while (width < term->width)
    	    {
    	      my_putstr(tigetstr("cuf1"));
    	      width++;
    	    }
    	  pos->x = term->width - 1;
    	  pos->y--;
    	}
      else
    	my_putchar('\b');
    }
}

static void	end_del(t_pos *tmp_pos, t_tty *term)
{
  if (tmp_pos->x < 0)
    {
      my_putstr(tigetstr("cuu1"));
      while (tmp_pos->x < term->width)
	{
	  tmp_pos->x++;
	  my_putstr(tigetstr("cuf1"));
	}
      my_putchar(' ');
    }
  my_putstr(" \b");
  restore_position(term, tmp_pos);
}

void	del_char(char *result, int *idx, t_tty *term)
{
  int	cpy_idx;
  t_pos	tmp_pos;

  go_left(&result, idx, tigetstr("kcub1"), term);
  tmp_pos.x = term->cur_pos.x;
  tmp_pos.y = term->cur_pos.y;
  cpy_idx = (*idx);
  while (result[cpy_idx] != 0)
    {
      my_putchar(result[cpy_idx + 1]);
      result[cpy_idx] = result[cpy_idx + 1];
      cpy_idx++;
      if (++tmp_pos.x == term->width)
	{
	  tmp_pos.x = 0;
	  tmp_pos.y++;
	  my_putchar('\n');
	}
    }
  tmp_pos.x--;
  end_del(&tmp_pos, term);
}
