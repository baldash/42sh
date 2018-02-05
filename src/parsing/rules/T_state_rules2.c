/*
** T_state_rules1.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 21:10:32 2016 Hugo Baldassin
** Last update Thu Jun 02 12:38:23 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"stack.h"
#include	"parser.h"

int		rule_7(t_stack **stack)
{
  replace_top_stack(*stack, NT_S, NULL);
  if (!(add_stack_elem(stack, IS_TERM, ";")))
    return (-1);
  (*stack)->insert_node = add_list;
  return (0);
}

int		rule_8(t_stack **stack)
{
  replace_top_stack(*stack, NT_H, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_first;
  return (0);
}
