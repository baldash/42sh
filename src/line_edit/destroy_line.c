/*
** destroy_line.c for 42sh  in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 21:11:14 2016 Hugo Willaume
** Last update Sun Jun  5 22:48:10 2016 Hugo Willaume
*/

#include	"line_edit.h"

int	destroy_line(char **result, int *idx, char *escape_seq,
		     t_tty *term)
{
  int	destroy_idx;

  if (escape_seq[0] != 21)
    return (1);
  end(result, idx, term->capacities[5], term);
  destroy_idx = (*idx) - 1;
  while (destroy_idx >= 0)
    {
      del_char((*result), idx, term);
      destroy_idx--;
    }
  return (0);
}
