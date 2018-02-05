/*
** H_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Sun Jun  5 23:58:24 2016 Hugo Baldassin
** Last update Sun Jun  5 23:58:26 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"stack.h"

int		rule_20(t_stack **stack)
{
  replace_top_stack(*stack, NT_H, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_arg;
  return (0);
}

int		rule_21(t_stack **stack)
{
  replace_top_stack(*stack, NT_O, NULL);
  (*stack)->error = ambiguous_output_redirect;
  if (!(add_stack_elem(stack, NT_J, NULL)))
    return (-1);
  return (0);
}

int		rule_22(t_stack **stack)
{
  replace_top_stack(*stack, NT_C, NULL);
  if (!(add_stack_elem(stack, NT_I, NULL)))
    return (-1);
  (*stack)->error = ambiguous_output_redirect;
  if (!(add_stack_elem(stack, NT_Q, NULL)))
    return (-1);
  return (0);
}

int		rule_23(t_stack **stack)
{
  replace_top_stack(*stack, NT_E, NULL);
  return (0);
}
