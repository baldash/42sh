/*
** exec_tree.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/execution/exec
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Fri May 06 09:06:22 2016 anthony
** Last update Wed Jun  8 21:16:11 2016 teisse_m
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<sys/signal.h>
#include	"types/struct_bintree.h"
#include	"environnement.h"
#include	"execution.h"
#include	"data.h"

void		wait_processus(t_binary_list *tree, t_data **info)
{
  int		status;

  status = 0;
  wait(&status);
  check_error_status(status);
  if (status)
    (*info)->exit_value = 1;
  tree->error_status += status;
}

int		exec_binary_tree(t_binary_list *tree, t_data **info)
{
  int		prog_count;

  while (tree != NULL)
    {
      (*info)->exit_value = 0;
      (*info)->is_exited = 0;
      if (tree->check_if_exec(tree->error_status) == true)
	{
	  if ((prog_count = exec_cmd_line(tree->root, info)) != -1)
	    {
	      exec_command_line(tree, info, tree);
	      close_pipes(tree->root, *info);
	      while (--prog_count >= 0)
		wait_processus(tree, info);
	    }
	  else
	    tree->error_status = 1;
	}
      if (tree->next)
	tree->next->error_status = tree->error_status;
      tree = tree->next;
    }
  return (1);
}
