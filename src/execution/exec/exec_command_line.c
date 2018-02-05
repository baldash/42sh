/*
** exec_command_line.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/execution
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Tue May 31 07:12:54 2016 Anthony LECLERC
** Last update Sun Jun  5 22:06:44 2016 Sylvain Chaugny
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/signal.h>
#include	"execution.h"
#include	"environnement.h"
#include	"data.h"

int		exec_command_line(t_binary_list *list, t_data **info,
				  t_binary_list *tree)
{
  t_binary_node	*exec;
  pid_t		pid;

  pid = 0;
  exec = list->root;
  if (exec_builtins(&exec, *info) == 0)
    {
      if ((pid = fork()) == -1)
	return (-1);
      if (pid == 0)
	{
	  signal(SIGINT, SIG_DFL);
	  if (dup_before_exec(list->root) == 1)
	    exit(1);
	  child_exec(list->root, (*info)->env);
	}
    }
  else
    tree->error_status = (*info)->exit_value;
  return ((*info)->exit_value);
}
