/*
** O_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 23:04:09 2016 Hugo Baldassin
** Last update Wed Jun 01 21:13:51 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"stack.h"

int		rule_29(t_stack **stack)
{
  replace_top_stack(*stack, NT_O, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_arg;
  return (0);
}

int		rule_30(t_stack **stack)
{
  replace_top_stack(*stack, NT_C, NULL);
  if (!(add_stack_elem(stack, NT_Q, NULL)))
    return (-1);
  return (0);
}

int		rule_31(t_stack **stack)
{
  replace_top_stack(*stack, NT_E, NULL);
  return (0);
}
