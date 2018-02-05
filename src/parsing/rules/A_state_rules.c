/*
** A_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 23:18:28 2016 Hugo Baldassin
** Last update Wed Jun 01 19:42:42 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"stack.h"

int		rule_35(t_stack **stack)
{
  replace_top_stack(*stack, NT_A, NULL);
  if (!(add_stack_elem(stack, NT_W, NULL)))
    return (-1);
  (*stack)->insert_node = add_arg;
  return (0);
}
