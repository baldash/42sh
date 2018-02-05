/*
** S_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 21:19:27 2016 Hugo Baldassin
** Last update Mon May 30 16:53:01 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"stack.h"

int		rule_1(t_stack **stack)
{
  replace_top_stack(*stack, NT_T, NULL);
  return (0);
}
