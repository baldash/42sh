/*
** Q_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 23:07:44 2016 Hugo Baldassin
** Last update Wed Jun 01 21:56:03 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"stack.h"
#include	"parser.h"

int		rule_32(t_stack **stack)
{
  replace_top_stack(*stack, NT_A, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = missing_name_redirect;
  if (!(add_stack_elem(stack, IS_TERM, ">>")))
    return (-1);
  (*stack)->insert_node = add_right_redir;
  return (0);
}

int		rule_33(t_stack **stack)
{
  replace_top_stack(*stack, NT_A, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = missing_name_redirect;
  if (!(add_stack_elem(stack, IS_TERM, ">")))
    return (-1);
  (*stack)->insert_node = add_right_redir;
  return (0);
}
