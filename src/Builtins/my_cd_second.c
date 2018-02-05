/*
** my_cd_second.c for 42sh  in /home/hurlu/rendu/PSU_2015_42sh/src/Builtins
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue May 31 15:12:37 2016 Hugo Willaume
** Last update Sun Jun  5 23:03:37 2016 Hugo Willaume
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	"data.h"

extern char *g_oldpwd;

char	*get_path(char **cmd)
{
  int		idx;

  idx = 1;
  while (cmd[idx] != NULL && strcmp(cmd[idx], "--") != 0
	 && (cmd[idx][0] == '-' && cmd[idx][1] != 0))
    idx++;
  if (cmd[idx] == NULL)
    return ("~");
  else if (cmd[idx + 1] != NULL)
    {
      fprintf(stderr, "cd: Too many arguments.\n");
      return (NULL);
    }
  else if (access(cmd[idx], F_OK | X_OK) == 0 || strcmp(cmd[idx], "-") == 0
	   || strcmp(cmd[idx], "~") == 0)
    return (cmd[idx]);
  if (access(cmd[idx], F_OK) == 0)
    {
      if (fprintf(stderr, "%s: Unauthorized permission\n", cmd[idx]))
	return (NULL);
    }
  else
    fprintf(stderr, "%s: No such directory\n", cmd[idx]);
  return (NULL);
}

int	get_to_oldpwd(t_data *data)
{
  char		*pwd;

  pwd = NULL;
  if (g_oldpwd == NULL)
    {
      fprintf(stderr, ": %s.\n", strerror(errno));
      return (1);
    }
  if (chdir(g_oldpwd) != 0)
    {
      fprintf(stderr, "%s.\n", strerror(errno));
      return (1);
    }
  if ((pwd = getcwd(pwd, 0)) == NULL)
    {
      fprintf(stderr, "%s.\n", strerror(errno));
      return (1);
    }
  my_modif_env(data, "PWD", g_oldpwd);
  return (0);
}

int	get_to_home(t_data *data)
{
  int		idx;
  char		*pwd;

  idx = 0;
  while (data->env[idx] != NULL && strncmp(data->env[idx], "HOME=", 5) != 0)
    idx++;
  if (data->env[idx] == NULL)
    {
      fprintf(stderr, ": %s.\n", strerror(errno));
      return (1);
    }
  if (chdir(&data->env[idx][5]) != 0)
    {
      fprintf(stderr, "%s.\n", strerror(errno));
      return (1);
    }
  pwd = NULL;
  if ((pwd = getcwd(pwd, 0)) == NULL)
    {
      fprintf(stderr, "%s.\n", strerror(errno));
      return (1);
    }
  my_modif_env(data, "PWD", pwd);
  return (0);
}
