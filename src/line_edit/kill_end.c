/*
** kill_end.c for 42sh  in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 22:36:34 2016 Hugo Willaume
** Last update Sun Jun  5 22:48:42 2016 Hugo Willaume
*/

#include	"line_edit.h"

int		kill_end(char **result, int *idx, char *escape_seq,
			 t_tty *term)
{
  if (escape_seq[0] != 11)
    return (1);
  while ((*result)[(*idx)] != 0)
    del(result, idx, term->capacities[6], term);
  return (0);
}
