/*
** pipe_exec.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/execution/redirections
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Tue May 10 10:32:27 2016 anthony
** Last update Wed Jun  8 21:14:59 2016 teisse_m
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/signal.h>
#include		"environnement.h"
#include		"execution.h"
#include		"data.h"
#include		"types/struct_bintree.h"

void			exec_pipe_child(t_binary_node *node, t_data *info)
{
  signal(SIGINT, SIG_DFL);
  close(node->iofd[0]);
  if (node->left->operator == L_PIPE)
    {
      close(node->left->iofd[1]);
      if (dup2(node->left->iofd[0], 0) == -1)
	exit_error("dup2 pipe input");
      close(node->left->iofd[0]);
    }
  else if (node->left->operator == L_RLEFT || node->left->operator == L_RDLEFT)
    {
      dup2(node->left->iofd[0], 0);
      close(node->left->iofd[0]);
    }
  if (dup2(node->iofd[1], 1) == -1)
    exit_error("dup2 pipe output");
  close(node->iofd[1]);
  close_pipes(node, NULL);
  if (exec_builtins(&(node->left), info) == 1)
    exit(0);
  child_exec(node->left, info->env);
  exit(1);
}

int			pipe_exec(t_binary_node *node, t_data **info)
{
  pid_t			pid;

  if (pipe(node->iofd) == -1)
    return (return_error("pipe"));
  pid = fork();
  if (pid == -1)
    return (return_error("fork"));
  if (pid == 0)
    exec_pipe_child(node, (*info));
  else
    {
      node->cmd = node->right->cmd;
      node->right->cmd = NULL;
    }
  return (0);
}
