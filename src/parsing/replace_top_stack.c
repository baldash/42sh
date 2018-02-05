/*
** replace_top_stack.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Mon May 30 14:17:26 2016 Anthony LECLERC
** Last update Sun Jun  5 22:54:17 2016 teisse_m
*/

#include	<stdlib.h>
#include	<string.h>
#include	"stack.h"
#include	"prototypes/errors_parsing.h"

int		replace_top_stack(t_stack *stack, t_noterm noterm,
				  const char *term)
{
  stack->noterm = noterm;
  free(stack->term);
  if (!term)
    {
      stack->term = NULL;
      stack->is_term = 0;
    }
  else
    {
      if ((stack->term = strdup(term)) == NULL)
	return (0);
      stack->is_term = 1;
    }
  return (1);
}
