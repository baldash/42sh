/*
** G_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/tmp/PSU_2015_42sh
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Sun Jun  5 16:29:02 2016 Hugo Baldassin
** Last update Mon Jun  6 00:16:56 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"stack.h"

int		rule_17(t_stack **stack)
{
  replace_top_stack(*stack, NT_O, NULL);
  (*stack)->error = ambiguous_input_redirect;
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_cmd;
  return (0);
}

int		rule_18(t_stack **stack)
{
  replace_top_stack(*stack, NT_C, NULL);
  if (!(add_stack_elem(stack, NT_A, NULL)))
    return (-1);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_cmd;
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = ambiguous_output_redirect;
  if (!(add_stack_elem(stack, IS_TERM, ">")))
    return (-1);
  (*stack)->insert_node = add_right_redir;
  return (0);
}

int		rule_19(t_stack **stack)
{
  replace_top_stack(*stack, NT_C, NULL);
  if (!(add_stack_elem(stack, NT_A, NULL)))
    return (-1);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_cmd;
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = ambiguous_output_redirect;
  if (!(add_stack_elem(stack, IS_TERM, ">>")))
    return (-1);
  (*stack)->insert_node = add_right_redir;
  return (0);
}
