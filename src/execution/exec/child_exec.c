/*
** child_exec.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/temp/execution
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Tue May 31 17:12:34 2016 teisse_m
** Last update Sun Jun  5 20:57:31 2016 teisse_m
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"execution.h"
#include	"environnement.h"

static char	*get_next_path(const char *path, const char *executable)
{
  size_t	lenght;
  char		*new_exec;

  if (path == NULL)
    return (NULL);
  lenght = strlen(path) + strlen(executable);
  new_exec = malloc(lenght + 2);
  if (new_exec == NULL)
    return (NULL);
  if (strcpy(new_exec, path) == NULL)
    return (NULL);
  new_exec[strlen(path)] = '/';
  if (strcpy(new_exec + strlen(path) + 1, executable) == NULL)
    return (NULL);
  new_exec[lenght + 1] = 0;
  return (new_exec);
}

void		exec_with_path(char **cmd, char **env)
{
  char		**path;
  char		*new_path;
  int		i;

  i = 0;
  path = get_path_wordtab(env);
  if (strcmp("\"", cmd[0]) == 0)
    {
      fprintf(stderr, "Unmatched \".\n");
      exit(1);
    }
  else if (path != NULL)
    {
      while ((new_path = get_next_path(path[i], cmd[0])) != NULL)
	{
	  execve(new_path, cmd, env);
	  free(new_path);
	  i++;
	}
    }
  fprintf(stderr, "%s: Command not found.\n", cmd[0]);
  exit(1);
}

static bool	scan_path_for_exec(const char *executable)
{
  while (*executable != '\0')
    {
      if (*executable == '.' || *executable == '/')
	return (0);
      executable++;
    }
  return (1);
}

int		child_exec(t_binary_node *node, char **env)
{
  if (scan_path_for_exec(node->cmd[0]) == true)
    exec_with_path(node->cmd, env);
  else
    exec_no_path(node->cmd, env);
  return (1);
}
