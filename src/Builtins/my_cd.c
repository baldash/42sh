/*
** my_cd.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh/src/Builtins
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Mon May 30 15:36:04 2016 Hugo Willaume
** Last update Sun Jun  5 23:03:07 2016 Hugo Willaume
*/

#include	<errno.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"data.h"

char		*g_oldpwd = NULL;

static int	get_args(char **input, int *arg)
{
  int		idx;
  int		idx_str;

  idx = 1;
  while (input[idx] != NULL && input[idx][0] == '-' && input[idx][1] != 0
	 && input[idx][1] != '-')
    {
      idx_str = 1;
      while (input[idx][idx_str] != 0)
	{
	  if (input[idx][idx_str] == 'p')
	    (*arg) = 1;
	  else
	    {
	      fprintf(stderr, "Usage : cd [-p] [-|<dir>].\n");
	      return (1);
	    }
	  idx_str++;
	}
      idx++;
    }
  return (0);
}

static int	print_path()
{
  char		*printable_path;

  printable_path = NULL;
  if ((printable_path = getcwd(printable_path, 0)) == NULL)
    {
      printf("%s\n", strerror(errno));
      return (1);
    }
  printf("%s\n", printable_path);
  free(printable_path);
  return (0);
}

static int	classic_cd(char *path, t_data *data)
{
  char		*pwd;

  if (chdir(path) != 0)
    {
      printf("%s\n", strerror(errno));
      return (1);
    }
  pwd = NULL;
  pwd = getcwd(pwd, 0);
  my_modif_env(data, "PWD", path);
  return (0);
}

static char	*get_oldpwd()
{
  char		*pwd;

  pwd = NULL;
  if ((pwd = getcwd(pwd, 0)) == NULL)
    {
      printf("%s\n", strerror(errno));
      return (NULL);
    }
  return (pwd);
}

int		my_cd(t_data *data, char **input)
{
  char		*path;
  int		arg;
  int		error;
  char		*pwd;

  arg = 0;
  if (get_args(input, &arg) != 0)
    return ((data->exit_value = 1));
  error = 0;
  if ((path = get_path(input)) == NULL || (pwd = get_oldpwd()) == NULL)
    return ((data->exit_value = 1));
  if (strcmp("-", path) == 0)
    error = get_to_oldpwd(data);
  else if (strcmp("~", path) == 0)
    error = get_to_home(data);
  else
    error = classic_cd(path, data);
  if (arg == 1 && error == 0)
    print_path();
  free(g_oldpwd);
  g_oldpwd = pwd;
  return (0);
}
