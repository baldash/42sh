/*
** my_strlen.c for 42sh in /home/anthony/documents/repository/PSU_2015_minishell2/src/misc
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Fri Apr  1 15:32:48 2016 anthony
** Last update Sun Jun  5 22:47:44 2016 teisse_m
*/

#include	<stdio.h>

size_t		my_strlen(const char *s)
{
  int		i;

  if (s == NULL)
    return (0);
  i = 0;
  while (s[i] != 0)
    i++;
  return (i);
}
