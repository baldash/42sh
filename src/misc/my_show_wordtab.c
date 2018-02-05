/*
** my_show_wordtab.c for 42sh my_show_wordtab in /home/baldas/Prog/repos/psu/PSU_2015_minishell2/basic
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Apr 25 20:45:53 2016 Hugo Baldassin
** Last update Sun Jun  5 22:46:38 2016 teisse_m
*/

#include	<stdlib.h>
#include	<stdio.h>

void		my_show_wordtab(char **tab)
{
  int		y;

  y = 0;
  while (tab[y] != NULL)
    {
      fprintf(stdout, "%s\n", tab[y]);
      y++;
    }
  fflush(stdout);
}
