/*
** left_key.c for 42sh  in /home/hurlu/PSU_2015_42sh/src/line_edit
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sat Jun  4 14:16:54 2016 Hugo Willaume
** Last update Sun Jun  5 23:05:57 2016 Hugo Willaume
*/

#include	<curses.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"misc.h"
#include	"line_edit.h"

static void	prev_line(int *idx, char **result, t_tty *term)
{
  (void)idx;
  (void)result;
  write(1, tigetstr("cuu1"), strlen(tigetstr("cuu1")));
  while (term->cur_pos.x < term->width - 1)
    {
      term->cur_pos.x++;
      write(1, tigetstr("cuf1"), strlen(tigetstr("cuf1")));
    }
  term->cur_pos.y--;
}

int	go_left(char **result, int *idx, char *escape_seq, t_tty *term)
{
  if (strcmp(escape_seq, term->capacities[0]) != 0 && escape_seq[0] != 2)
    return (1);
  if ((*idx) > 0)
    {
      if (term->cur_pos.x == 0)
	prev_line(idx, result, term);
      else
	{
	  term->cur_pos.x--;
	  write(1, "\b", 1);
	}
      (*idx)--;
    }
  return (0);
}
