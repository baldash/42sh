/*
** my_setenv.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh/src/Builtins
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue May 31 16:07:01 2016 Hugo Willaume
** Last update Sun Jun  5 23:04:38 2016 Hugo Willaume
*/

#include		<stdio.h>
#include		<unistd.h>
#include		"misc.h"
#include		"data.h"
#include		"bool.h"

t_bool		check_if_name_is_correct(char *name)
{
  int			i;

  i = 0;
  if ((name[i] < 'a' || name[i] > 'z') &&
      (name[i] < 'A' || name[i] > 'Z'))
    {
      fprintf(stderr, "Variable name must begin with a letter.\n");
      return (FALSE);
    }
  while (name[i] != 0)
    {
      if ((name[i] < 'a' || name[i] > 'z') &&
	  (name[i] < 'A' || name[i] > 'Z') &&
	  (name[i] < '0' || name[i] > '9'))
	{
	  fprintf(stderr, "Variable name must contain"
		  " alphanumeric characters.\n");
	  return (FALSE);
	}
      i++;
    }
  return (TRUE);
}

int		my_setenv(t_data *data, char **input)
{
  if (my_tablen(input) > 3)
    {
      fprintf(stderr, "setenv: Too many arguments.\n");
      return (2);
    }
  if (input[1] == NULL)
    my_show_wordtab(data->env);
  else if (check_if_name_is_correct(input[1]) == FALSE)
    return (3);
  else
    if (my_modif_env(data, input[1], input[2]) == 1)
      return (1);
  return (0);
}
