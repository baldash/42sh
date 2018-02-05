/*
** term_match.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Fri May 27 18:21:44 2016 Hugo Baldassin
** Last update Fri May 27 19:07:24 2016 Hugo Baldassin
*/

#include	"stack.h"

const char	*term_match(t_stack *stack, const char *str)
{
  const char	*p;
  int		i;

  i = 0;
  p = str;
  while (p[0] && stack->term[i])
    {
      if (p[0] != stack->term[i])
	return (str);
      p++;
      i++;
    }
  return (p);
}
