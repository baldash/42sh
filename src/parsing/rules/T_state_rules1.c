/*
** T_state_rules1.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 21:10:32 2016 Hugo Baldassin
** Last update Wed Jun 01 21:51:49 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"stack.h"

int		rule_3(t_stack **stack)
{
  replace_top_stack(*stack, NT_C, NULL);
  if (!(add_stack_elem(stack, NT_F, NULL)))
    return (-1);
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = missing_name_redirect;
  if (!(add_stack_elem(stack, IS_TERM, ">")))
    return (-1);
  (*stack)->insert_node = add_first;
  return (0);
}

int		rule_4(t_stack **stack)
{
  replace_top_stack(*stack, NT_G, NULL);
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = missing_name_redirect;
  if (!(add_stack_elem(stack, IS_TERM, "<")))
    return (-1);
  (*stack)->insert_node = add_first;
  return (0);
}

int		rule_5(t_stack **stack)
{
  replace_top_stack(*stack, NT_C, NULL);
  if (!(add_stack_elem(stack, NT_F, NULL)))
    return (-1);
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = missing_name_redirect;
  if (!(add_stack_elem(stack, IS_TERM, ">>")))
    return (-1);
  (*stack)->insert_node = add_first;
  return (0);
}

int		rule_6(t_stack **stack)
{
  replace_top_stack(*stack, NT_G, NULL);
  (*stack)->error = invalid_null_command;
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = missing_name_redirect;
  if (!(add_stack_elem(stack, IS_TERM, "<<")))
    return (-1);
  (*stack)->insert_node = add_first;
  return (0);
}
