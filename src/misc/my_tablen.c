/*
** my_tablen.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/misc
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Tue May 24 20:38:50 2016 Hugo Baldassin
** Last update Tue May 31 16:15:19 2016 Gabriel Forteville
*/

#include	<stdlib.h>

int		my_tablen(char **tab)
{
  int		y;

  if (tab == NULL)
    return (0);
  y = 0;
  while (tab[y])
    y++;
  return (y);
}
