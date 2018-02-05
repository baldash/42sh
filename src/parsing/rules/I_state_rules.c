/*
** I_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 22:01:22 2016 Hugo Baldassin
** Last update Sun Jun  5 20:17:20 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"stack.h"

int		rule_24(t_stack **stack)
{
  replace_top_stack(*stack, NT_I, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_arg;
  return (0);
}

int		rule_25(t_stack **stack)
{
  replace_top_stack(*stack, NT_J, NULL);
  return (0);
}

int		rule_26(t_stack **stack)
{
  replace_top_stack(*stack, NT_C, NULL);
  return (0);
}
