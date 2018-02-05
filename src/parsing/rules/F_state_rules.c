/*
** F_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 21:41:02 2016 Hugo Baldassin
** Last update Wed Jun 01 21:53:49 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"stack.h"
#include	"parser.h"

int		rule_14(t_stack **stack)
{
  replace_top_stack(*stack, NT_I, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_cmd;
  return (0);
}

int		rule_15(t_stack **stack)
{
  replace_top_stack(*stack, NT_A, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->error = invalid_null_command;
  (*stack)->insert_node = add_cmd;
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = missing_name_redirect;
  if (!(add_stack_elem(stack, IS_TERM, "<")))
    return (-1);
  (*stack)->insert_node = add_left_redir;
  return (0);
}

int		rule_16(t_stack **stack)
{
  replace_top_stack(*stack, NT_A, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->error = invalid_null_command;
  (*stack)->insert_node = add_cmd;
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->error = missing_name_redirect;
  (*stack)->insert_node = add_file;
  if (!(add_stack_elem(stack, IS_TERM, "<<")))
    return (-1);
  (*stack)->insert_node = add_left_redir;
  return (0);
}
