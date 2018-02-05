/*
** J_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 23:00:39 2016 Hugo Baldassin
** Last update Wed Jun 01 21:54:14 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"stack.h"
#include	"parser.h"
#include	"types/struct_bintree.h"

int		rule_27(t_stack **stack)
{
  replace_top_stack(*stack, NT_A, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = missing_name_redirect;
  if (!(add_stack_elem(stack, IS_TERM, "<")))
    return (-1);
  (*stack)->insert_node = add_left_redir;
  return (0);
}

int		rule_28(t_stack **stack)
{
  replace_top_stack(*stack, NT_A, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_file;
  (*stack)->error = missing_name_redirect;
  if (!(add_stack_elem(stack, IS_TERM, "<<")))
    return (-1);
  (*stack)->insert_node = add_left_redir;
  return (0);
}
