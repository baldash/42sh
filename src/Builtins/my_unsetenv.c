/*
** my_unsetenv.c for 42sh in /home/hurlu/PSU_2015_42sh/src/Builtins
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue May 31 16:37:32 2016 Hugo Willaume
** Last update Sun Jun  5 23:04:50 2016 Hugo Willaume
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"data.h"

static void	unset_var(char *input, t_data *data)
{
  int		idx;

  idx = 0;
  while (data->env[idx] != NULL)
    {
      if (strncmp(data->env[idx], input, strlen(input)) == 0 &&
	  data->env[idx][strlen(input)] == '=')
	{
	  free(data->env[idx]);
	  while (data->env[idx] != NULL)
	    {
	      data->env[idx] = data->env[idx + 1];
	      idx++;
	    }
	}
      else
	idx++;
    }
}

int		my_unsetenv(t_data *data, char **input)
{
  int		idx;

  idx = 1;
  if (input[1] == NULL)
    {
      fprintf(stderr, "unsetenv: Too few arguments.\n");
      return (1);
    }
  while (input[idx] != NULL)
    {
      unset_var(input[idx], data);
      idx++;
    }
  return (0);
}
