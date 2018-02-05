/*
** init_shell.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 14:28:22 2016 Hugo Willaume
** Last update Thu Jun  9 13:02:27 2016 Sylvain Chaugny
*/

#include	<string.h>
#include	<stdio.h>
#include	<sys/ioctl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"data.h"
#include	"environnement.h"
#include	"misc.h"

extern char	*g_oldpwd;

void		free_shell(t_data *info, t_terminals *terms, int error)
{
  if (isatty(0) != 0)
    {
      finish_history(info);
      free_hist(info);
      free(info->history.path);
      if (error != 3)
	ioctl(0, TCSETS, &terms->term);
    }
  free_tab(info->env);
  free(g_oldpwd);
}

static int	check_term(char **env)
{
  int		idx;

  idx = 0;
  while (env[idx] != NULL && strncmp("TERM=", env[idx], 5) != 0)
    idx++;
  if (env[idx] == NULL)
    {
      fprintf(stderr, "Disabling line editing : no TERM env value\n");
      return (1);
    }
  else
    return (0);
}

int		init_shell(t_data *info_shell, t_terminals *terms, char **env)
{
  info_shell->history.history_size = 1000;
  info_shell->env = env_copy(env);
  info_shell->is_exited = 0;
  init_builtins_structure(info_shell);
  if (get_path_history(&(info_shell->history)) == 2)
    return (2);
  if (isatty(0) != 0)
    {
      if (check_term(env) != 0)
	return (3);
      else if ((init_term(&terms->tty, &terms->term, &terms->new_term)) != 0)
	return (1);
    }
  return (0);
}
