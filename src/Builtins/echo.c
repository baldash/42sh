/*
** echo.c for PSU_2015_42sh in /home/fortevg/rendu/PSU/PSU_2015_42sh/src/Builtins
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri May 20 17:06:29 2016 Forteville Gabriel
** Last update Sun Jun  5 20:35:34 2016 Sylvain Chaugny
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"misc.h"
#include	"bool.h"
#include	"data.h"

static int	print_val_var_env(t_data *data, int index)
{
  int		tmp;

  tmp = 0;
  if (data->env != NULL && data->env[index] != NULL)
    {
      while (data->env[index][tmp] != 0 && data->env[index][tmp] != '=')
	tmp++;
      tmp++;
      while (data->env[index][tmp] != 0)
	{
	  if (fprintf(stdout, "%c", data->env[index][tmp]) < 0)
	    return (2);
	  tmp++;
	}
    }
  return (0);
}

static int	check_var_env(t_data *data, char *var_env)
{
  int		index;

  index = 0;
  while (var_env != NULL && data->env != NULL && data->env[index] != NULL &&
	 var_is(var_env, data->env[index]) == FALSE)
    index++;
  if (var_env == NULL || data->env == NULL || data->env[index] == NULL)
    {
      if (fprintf(stderr, "\"%s\": Undefined variable.\n", var_env) < 0)
	return (2);
      return (-1);
    }
  free (var_env);
  return (print_val_var_env(data, index));
}


static int	recup_var_env(t_data *data, char *input, int pos)
{
  int		index;
  char		*var_env;

  index = 1;
  var_env = NULL;
  if (input[pos] == 0)
    {
      if (fprintf(stdout, "$") < 0)
	return (2);
      return (0);
    }
  if (input[pos] == '$')
    {
      if (fprintf(stdout, "%i", getpid()) < 0)
	return (2);
      return (0);
    }
  while (input[pos] != 0 && input[pos] != '$')
    {
      if ((var_env = realloc(var_env, (index + 1))) == NULL)
	return (1);
      var_env[index] = 0;
      var_env[index - 1] = input[pos];
      index++;
      pos++;
    }
  return (check_var_env(data, var_env));
}

static int	write_all(t_data *data, char **input, int index)
{
  int		return_val;
  int		print;

  print = 0;
  while (input[index][print] != 0)
    {
      return_val = -123;
      if (input[index][print] == '$' &&
	  (return_val = recup_var_env(data, input[index], print + 1)) != 0)
	return (return_val);
      else if (return_val == -123)
	fprintf(stdout, "%c", input[index][print]);
      else if (input[index][print] == '$' && input[index][print + 1] == '$')
	print++;
      else
	while (input[index][print + 1] != 0 && input[index][print + 1] != '$')
	  print++;
      print++;
    }
  return (0);
}

int		echo(t_data *data, char **input)
{
  int		index;
  int		tab_len;
  bool		not_new_line;
  int		return_val;

  if (input == NULL || input[1] == NULL)
    return (0);
  not_new_line = my_strcompare(input[1], "-n");
  tab_len = my_tablen(input);
  index = not_new_line + 1;
  while (index < tab_len)
    {
      if ((return_val = write_all(data, input, index)) > 0)
	return (return_val);
      if (return_val == -1)
	return (0);
      if (index < tab_len - 1)
	fprintf(stdout, " ");
      index++;
    }
  if (not_new_line == FALSE)
    fprintf(stdout, "\n");
  fflush(stdout);
  return (0);
}
