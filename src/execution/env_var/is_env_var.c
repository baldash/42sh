/*
** dup_before_exec.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/execution/exec
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Wed May 11 13:46:13 2016 anthony
** Last update Wed Jun  8 21:14:37 2016 teisse_m
*/

#include	<stdlib.h>
#include	<stdbool.h>
#include	"environnement.h"

size_t		get_len_env_var(const char *env_v)
{
  size_t	i;

  i = 0;
  while (env_v[i] != 0 && env_v[i] != '=')
    i++;
  return (i);
}

bool		is_env_var(const char *env_v, const char *var)
{
  while (*env_v == *var && *var != 0 && *env_v != 0)
    {
      env_v++;
      var++;
      if (*env_v == '=' && *var == 0)
	return (true);
    }
  return (false);
}

int		is_var_in_environ(const char *variable, char **env)
{
  int		i;

  i = 0;
  while (env[i] != NULL && is_env_var(env[i], variable) == false)
    i++;
  return ((env[i] == NULL) ? -1 : i);
}
