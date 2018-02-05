/*
** free_wordtab.c for 42sh in /home/lecler_1/repository/PSU_2015_42sh/src/execution/environement
**
** Made by Anthony Leclerc
** Login   <lecler_1@epitech.net>
**
** Started on  Thu Jan  7 14:22:45 2016 Anthony Leclerc
** Last update Wed Jun  8 21:17:41 2016 teisse_m
*/

#include	<stdlib.h>

int		my_free_wordtab(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL)
    return (1);
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (0);
}
