/*
** word_left.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 17:30:12 2016 Hugo Willaume
** Last update Thu Jun  9 12:46:15 2016 Hugo Willaume
*/

#include	<curses.h>
#include	<string.h>
#include	"line_edit.h"

int		word_left(char **result, int *idx, char *escape_seq,
			  t_tty *term)
{
  if (strcmp(escape_seq, term->capacities[2]) != 0 || (*idx) == 0)
    return (1);
  go_left(result, idx, term->capacities[0], term);
  while ((*idx) > 1 && (*result)[(*idx)] == ' ')
    go_left(result, idx, term->capacities[0], term);
  while ((*idx) > 0 && (*result)[(*idx) - 1] != ' ')
     go_left(result, idx, term->capacities[0], term);
  if ((*idx) == 1 && (*result)[(*idx)] == ' ')
    go_left(result, idx, term->capacities[0], term);
  return (0);
}
