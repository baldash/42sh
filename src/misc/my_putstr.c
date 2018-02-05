/*
** my_putstr.c for 42sh in /home/anthony/documents/repository/PSU_2015_minishell2/src/misc
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Fri Apr  1 15:34:50 2016 anthony
** Last update Sun Jun  5 22:46:24 2016 teisse_m
*/

#include	<unistd.h>
#include	"misc.h"

void		my_putstr(const char *s)
{
  write(1, s, my_strlen(s));
}
