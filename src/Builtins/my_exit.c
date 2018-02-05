/*
** my_exit.c for  in /home/lecler_1/repository/PSU_2015_42sh/src/Builtins
**
** Made by Anthony Leclerc
** Login   <lecler_1@epitech.net>
**
** Started on  Thu Jan 21 07:51:09 2016 Anthony Leclerc
** Last update Sun Jun  5 23:03:53 2016 Hugo Willaume
*/

#include		<stdio.h>
#include		<string.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"misc.h"
#include		"data.h"

int			my_str_isnum(char *str)
{
  if (*str == '\0')
    return (0);
  while (*str)
    {
      if (*str < '0' || *str > '9')
	return (0);
      str++;
    }
  return (1);
}

int			get_exit_code(char *code)
{
  unsigned char		nbr;
  int			i;
  int			n;

  n = 10;
  if (my_str_isnum((*code == '-') ? code + 1 : code) == 0)
    return (-1);
  i = strlen(code) - 1;
  nbr = 0;
  nbr += code[i] - 48;
  while (i > (code[0] == '-') ? 1 : 0)
    {
      i--;
      nbr += ((code[i] - 48) * (n));
      n *= 10;
    }
  nbr = (code[0] == '-') ? 256 - nbr : nbr;
  return ((int)nbr);
}

int			my_exit(t_data *info, char **args)
{
  int			exit_code;

  (void)info;
  if (my_tablen(args) > 2)
    {
      fprintf(stderr, "exit : Expression Syntax.\n");
      return (0);
    }
  if (args[1] == NULL)
    {
      info->exit_value = 0;
      info->is_exited = 1;
    }
  else
    {
      if ((exit_code = get_exit_code(args[1])) == -1)
	{
	  fprintf(stderr, "exit : Expression Syntax.\n");
	  return (0);
	}
      info->exit_value = exit_code;
      info->is_exited = 1;
    }
  return (0);
}
