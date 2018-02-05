/*
** start.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 17:31:35 2016 Hugo Willaume
** Last update Sun Jun  5 22:49:21 2016 Hugo Willaume
*/

#include	<string.h>
#include	"line_edit.h"

int	start(char **result, int *idx, char *escape_seq,
	      t_tty *term)
{
  if (escape_seq[0] != 1 && strcmp(escape_seq, term->capacities[4]) != 0)
    return (1);
  while ((*idx) != 0)
    go_left(result, idx, term->capacities[0], term);
  return (0);
}
