/*
** P_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 23:13:47 2016 Hugo Baldassin
** Last update Mon May 30 14:39:06 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"stack.h"

int		rule_34(t_stack **stack)
{
  replace_top_stack(*stack, NT_G, NULL);
  return (0);
}
