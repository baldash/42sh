/*
** get_env_var.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/Builtins
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Tue Apr 12 19:46:19 2016 anthony
** Last update Sun Jun  5 23:02:34 2016 Hugo Willaume
*/

#include		"environnement.h"

char			*get_env(char **env, const char *key)
{
  int			i;
  char			*value;

  if ((i = is_var_in_environ(key, env)) == -1)
    return (NULL);
  value = env[i];
  while (*value != '=' && *value != 0)
    value++;
  if (*value == 0)
    return (value);
  else
    return (value + 1);
}
