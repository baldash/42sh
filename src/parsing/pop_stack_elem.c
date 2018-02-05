/*
** pop_stack_elem.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed May 25 01:08:43 2016 Hugo Baldassin
** Last update Sat May 28 17:40:56 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"stack.h"

void		pop_stack_elem(t_stack **stack)
{
  t_stack	*tmp;

  tmp = (*stack);
  (*stack) = tmp->next;
  free(tmp->term);
  free(tmp);
}
