/*
** env_copy.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/execution/environement
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Tue Apr 12 13:32:42 2016 anthony
** Last update Wed Jun  8 21:16:57 2016 teisse_m
*/

#include		<stdio.h>
#include		<string.h>
#include		"environnement.h"
#include		"misc.h"

char			**env_copy(char **env)
{
  char			**nwenv;
  size_t		env_len;

  env_len = my_wordtab_len(env);
  nwenv = malloc((env_len + 1) * sizeof(char *));
  if (nwenv == NULL)
    return (NULL);
  nwenv[env_len] = NULL;
  while (env_len-- > 0)
    {
      if ((nwenv[env_len] = strdup(env[env_len])) == NULL)
	{
	  my_perror("strdup");
	  return (NULL);
	}
    }
  return (nwenv);
}
