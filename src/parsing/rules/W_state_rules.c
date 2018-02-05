/*
** W_state_rules.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/rules
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 23:33:54 2016 Hugo Baldassin
** Last update Mon May 30 14:46:20 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"stack.h"

int		rule_37(t_stack **stack, const char *str)
{
  char		*word;

  word = get_word(str);
  if (word == NULL)
    return (1);
  if (replace_top_stack(*stack, IS_TERM, word) == 1)
    {
      free(word);
      return (1);
    }
  free(word);
  return (0);
}
