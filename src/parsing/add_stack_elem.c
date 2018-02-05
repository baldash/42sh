/*
** add_stack_elem.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed May 25 01:10:37 2016 Hugo Baldassin
** Last update Wed Jun 01 23:10:18 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	<string.h>
#include	"stack.h"
#include	"prototypes/errors_parsing.h"

int		add_stack_elem(t_stack **stack, t_noterm noterm,
			       const char *term)
{
  t_stack	*new;

  if (!(new = calloc(1, sizeof(t_stack))))
    return (0);
  new->noterm = noterm;
  if (!term)
    {
      new->term = NULL;
      new->is_term = 0;
    }
  else
    {
      new->term = strdup(term);
      if (new->term == NULL)
	return (0);
      new->is_term = 1;
    }
  new->next = (*stack);
  (*stack) = new;
  return (1);
}
