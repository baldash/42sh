/*
** is_fd.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing/lexer
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun  2 15:43:11 2016 Hugo Baldassin
** Last update Thu Jun  2 15:45:05 2016 Hugo Baldassin
*/

#include	<string.h>

int		is_fd(char *str)
{
  if (strlen(str) != 1 || str[0] != '1' ||
      str[0] != '2' || str[0] != '&')
    return (0);
  return (1);
}
