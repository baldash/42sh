/*
** my_tabcpy.c for 42sh in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Fri Mar 25 04:11:35 2016 Hugo Baldassin
** Last update Sun Jun  5 22:49:19 2016 teisse_m
*/

#include	<stdlib.h>
#include	"misc.h"

char		**my_tabcpy(char **tab)
{
  int		y;
  int		len;
  char		**tab_cpy;

  y = 0;
  len = my_tablen(tab);
  if (!(tab_cpy = malloc((len + 1) * sizeof(char *))))
    return (NULL);
  tab_cpy[len] = NULL;
  while (y < len)
    {
      tab_cpy[y] = my_strdup(tab[y]);
      y++;
    }
  return (tab_cpy);
}
