/*
** my_str_to_wordtab.c for 42sh in /home/sylvain/Documents/zone_tests/PSU/PSU_2015_minishell1
**
** Made by Sylvain Chaugny
** Login   <sylvain@epitech.net>
**
** Started on  Fri Jan  8 11:45:44 2016 Sylvain Chaugny
** Last update Sun Jun  5 22:48:04 2016 teisse_m
*/

#include	<stdlib.h>
#include	"wordtab.h"
#include	"misc.h"

int		is_limit(t_wordtab		*wt,
			 char			c)
{
  int		i;

  i = -1;
  while (wt->limits[++i])
    if (c == wt->limits[i])
      return (1);
  return (0);
}

void		parse_str(t_wordtab		*wt,
			  int			*i,
			  int			*j)
{
  int		tmp;

  while (wt->str[*i] && is_limit(wt, wt->str[*i]))
    (*i)++;
  if (wt->str[*i] == 0)
    return ;
  tmp = *i;
  while (wt->str[*i] && is_limit(wt, wt->str[*i]) == 0)
    (*i)++;
  if ((wt->wordtab[*j] = malloc(sizeof(char) * (*i - tmp + 1))) == NULL)
    return ;
  *i = tmp;
  tmp = 0;
  while (wt->str[*i] && is_limit(wt, wt->str[*i]) == 0)
    {
      wt->wordtab[*j][tmp] = wt->str[*i];
      (*i)++;
      tmp++;
    }
  wt->wordtab[*j][tmp] = 0;
  (*j)++;
}

char		**my_str_to_wordtab(char	*str,
				    char	*limits)
{
  t_wordtab	wt;
  int		i;
  int		j;

  wt.str = str;
  wt.limits = limits;
  if (str == NULL || my_strlen(str) == 0 || limits == NULL || limits[0] == 0)
    return (NULL);
  if ((wt.wordtab = malloc(sizeof(char *) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (i < my_strlen(wt.str))
    parse_str(&wt, &i, &j);
  wt.wordtab[j] = NULL;
  return (wt.wordtab);
}
