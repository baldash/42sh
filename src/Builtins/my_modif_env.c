/*
** my_modif_env.c for 42sh in /home/fortevg/rendu/PSU/PSU_2015_42sh/src/Builtins
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon May 30 17:45:42 2016 Gabriel Forteville
** Last update Sun Jun  5 14:18:33 2016 Gabriel Forteville
*/

#include	<stdlib.h>
#include	<stdio.h>
#include        <unistd.h>
#include	<string.h>
#include	<errno.h>
#include	"data.h"
#include	"bool.h"
#include	"misc.h"

static int	new_env(t_data *data,
			int len,
			char *name_env,
			char *value_env)
{
  (void)name_env;
  (void)value_env;
  data->env = realloc(data->env, sizeof(char *) * (len + 2));
  if (data->env == NULL)
    {
      printf("malloc: %s\n", strerror(errno));
      return (1);
    }
  data->env[len + 1] = NULL;
  return (0);
}

t_bool	var_is(char *name_env, char *var_env)
{
  int		index;

  index = 0;
  while (name_env[index] != 0 && var_env[index] != 0 &&
	 name_env[index] == var_env[index])
    index++;
  if (var_env[index] == '=' && name_env[index] == 0)
    return (TRUE);
  return (FALSE);
}

static char		*two_to_one_str(char *str1, char *str2)
{
  char			*result;
  int			index_str1;
  int			index_str2;

  index_str1 = -1;
  index_str2 = -1;
  result = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));
  if (result == NULL)
    return (NULL);
  while (str1[++index_str1] != 0)
    result[index_str1] = str1[index_str1];
  result[index_str1] = '=';
  index_str1++;
  if (str2 != NULL)
    while (str2[++index_str2] != 0)
      {
	result[index_str1] = str2[index_str2];
	index_str1++;
      }
  result[index_str1] = 0;
  return (result);
}

int		my_modif_env(t_data *data,
			     char *name_env,
			     char *value_env)
{
  int		index;
  int		len;

  index = 0;
  len = my_tablen(data->env);
  while (index < len && var_is(name_env, data->env[index]) != TRUE)
    index++;
  if (index == len)
    {
      if (new_env(data, len, name_env, value_env) == -1)
	return (1);
      if ((data->env[len] = two_to_one_str(name_env, value_env)) == NULL)
	return (1);
    }
  else
    {
      free(data->env[index]);
      data->env[index] = two_to_one_str(name_env, value_env);
    }
  return (0);
}
