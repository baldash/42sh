/*
** E_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 21:37:43 2016 Hugo Baldassin
** Last update Sun Jun  5 23:57:21 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"stack.h"
#include	"parser.h"

int		rule_9(t_stack **stack)
{
  replace_top_stack(*stack, NT_P, NULL);
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, IS_TERM, "|")))
    return (-1);
  (*stack)->insert_node = add_pipe;
  return (0);
}

int		rule_10(t_stack **stack)
{
  replace_top_stack(*stack, NT_C, NULL);
  (*stack)->error = ambiguous_output_redirect;
  return (0);
}

int		rule_11(t_stack **stack)
{
  replace_top_stack(*stack, NT_T, NULL);
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, IS_TERM, "&&")))
    return (-1);
  (*stack)->insert_node = add_list;
  return (0);
}

int		rule_12(t_stack **stack)
{
  replace_top_stack(*stack, NT_T, NULL);
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, IS_TERM, "||")))
    return (-1);
  (*stack)->insert_node = add_list;
  return (0);
}

int		rule_13(t_stack **stack)
{
  replace_top_stack(*stack, NT_S, NULL);
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, IS_TERM, ";")))
    return (-1);
  (*stack)->insert_node = add_list;
  return (0);
}
