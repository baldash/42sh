/*
** my_show_wordtab.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/temp/execution
** 
** Made by teisse_m
** Login   <teisse_m@epitech.net>
** 
** Started on  Tue May 31 17:11:11 2016 teisse_m
** Last update Tue May 31 17:11:12 2016 teisse_m
*/

#include	<stdio.h>
#include	<unistd.h>

int		my_show_wordtab(char **tab)
{
  int		count;

  count = 0;
  if (tab == NULL)
    return (1);
  while (tab[count] != NULL)
    {
      printf("%s\n", tab[count]);
      count++;
    }
  return (0);
}
