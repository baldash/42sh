/*
** free_tab.c for 42sh free_tab in /home/baldas/Prog/libs/libmy
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Tue Mar 15 18:20:08 2016 Hugo Baldassin
** Last update Sun Jun  5 22:44:26 2016 teisse_m
*/

#include	<stdlib.h>

void		free_tab(char **tab)
{
  int		y;

  y = 0;
  if (tab != NULL)
    {
      while (tab[y] != NULL)
	{
	  free(tab[y]);
	  y++;
	}
      free(tab);
    }
}
