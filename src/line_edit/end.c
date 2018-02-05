/*
** end.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 17:31:52 2016 Hugo Willaume
** Last update Sun Jun  5 22:48:24 2016 Hugo Willaume
*/

#include	<string.h>
#include	"line_edit.h"

int	end(char **result, int *idx, char *escape_seq,
	    t_tty *term)
{
  if (escape_seq[0] != 5 && strcmp(escape_seq, term->capacities[5]) != 0)
    return (1);
  while ((*result)[(*idx)] != 0)
    go_right(result, idx, term->capacities[1], term);
  return (0);
}
