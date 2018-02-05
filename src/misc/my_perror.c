/*
** my_perror.c for 42sh in /home/anthony/documents/repository/PSU_2015_minishell2/src/misc
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Fri Apr  1 15:37:56 2016 anthony
** Last update Sun Jun  5 22:45:57 2016 teisse_m
*/

#include	<unistd.h>
#include	"misc.h"

int		put_error(char *s)
{
  write(2, s, my_strlen(s));
  return (2);
}

void		my_perror(const char *s)
{
  write(2, s, my_strlen(s));
}
