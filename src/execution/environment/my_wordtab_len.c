/*
** my_wordtab_len.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/execution/environment
** 
** Made by teisse_m
** Login   <teisse_m@epitech.net>
** 
** Started on  Sun Jun  5 22:59:59 2016 teisse_m
** Last update Sun Jun  5 23:00:00 2016 teisse_m
*/

#include	<stdlib.h>

size_t		my_wordtab_len(char **tab)
{
  size_t	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    i++;
  return (i);
}
