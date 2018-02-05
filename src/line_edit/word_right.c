/*
** word_right.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 17:31:00 2016 Hugo Willaume
** Last update Sun Jun  5 22:49:36 2016 Hugo Willaume
*/

#include	<string.h>
#include	"line_edit.h"

int	word_right(char **result, int *idx, char *escape_seq,
		   t_tty *term)
{
  if (strcmp(escape_seq, term->capacities[3]) != 0 || (*result)[(*idx)] == 0)
    return (1);
  go_right(result, idx, term->capacities[1], term);
  while ((*result)[(*idx)] == ' ')
    go_right(result, idx, term->capacities[1], term);
  while ((*result)[(*idx)] != 0 && (*result)[(*idx)] != ' ')
    go_right(result, idx, term->capacities[1], term);
  return (0);
}
