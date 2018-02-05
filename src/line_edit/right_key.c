/*
** right_key.c for 42sh in /home/hurlu/PSU_2015_42sh/src/line_edit/
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sat Jun  4 14:20:30 2016 Hugo Willaume
** Last update Sun Jun  5 23:06:19 2016 Hugo Willaume
*/

#include	<unistd.h>
#include	<string.h>
#include	<curses.h>
#include	"misc.h"
#include	"line_edit.h"

int	go_right(char **result, int *idx, char *escape_seq, t_tty *term)
{
  if (strcmp(escape_seq, term->capacities[1]) != 0 && escape_seq[0] != 6)
    return (1);
  if ((*result)[(*idx)] != 0)
    {
      term->cur_pos.x++;
      my_putstr(tigetstr("cuf1"));
      (*idx)++;
      if (term->cur_pos.x == term->width)
	{
	  my_putchar('\n');
	  term->cur_pos.x = 0;
	  term->cur_pos.y++;
	}
    }
  return (0);
}
