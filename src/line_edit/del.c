/*
** del.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 22:25:20 2016 Hugo Willaume
** Last update Sun Jun  5 22:47:49 2016 Hugo Willaume
*/

#include	<string.h>
#include	"line_edit.h"

int	del(char **result, int *idx, char *escape_seq,
	    t_tty *term)
{
  if (strcmp(escape_seq, term->capacities[6]) != 0 ||
      (*result)[(*idx)] == 0)
    return (1);
  go_right(result, idx, term->capacities[1], term);
  del_char((*result), idx, term);
  return (0);
}
