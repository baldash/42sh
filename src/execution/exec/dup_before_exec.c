/*
** dup_before_exec.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/execution/exec
** 
** Made by teisse_m
** Login   <teisse_m@epitech.net>
** 
** Started on  Sun Jun  5 23:02:18 2016 teisse_m
** Last update Sun Jun  5 23:02:18 2016 teisse_m
*/

#include		<stdio.h>
#include		<unistd.h>
#include		"types/struct_bintree.h"
#include		"misc.h"
#include		"execution.h"

static int		dup_redir(t_binary_node *node)
{
  if (IS_OUTPUT(node->operator))
    {
      if (dup2(node->iofd[1], 1) == -1)
	{
	  my_perror("Error: 'dup2' function failed\n");
	  return (1);
	}
    }
  else if (IS_INPUT(node->operator))
    {
      if (dup2(node->iofd[0], 0) == -1)
	{
	  my_perror("Error: 'dup2' function failed\n");
	  return (1);
	}
    }
  return (0);
}

int			dup_pipe(t_binary_node *node)
{
  if (dup2(node->iofd[0], 0) == -1)
    {
      my_perror("Error: 'dup2' function failed\n");
      return (1);
    }
  close(node->iofd[0]);
  if (IS_OUTPUT(node->right->operator))
    {
      if (dup2(node->right->iofd[1], 1) == -1)
	{
	  my_perror("Error: 'dup2' function failed\n");
	  return (1);
	}
      close(node->right->iofd[1]);
    }
  close(node->iofd[1]);
  close_pipes(node, NULL);
  return (0);
}

int			dup_before_exec(t_binary_node *node)
{
  if (node->operator == L_PIPE)
    {
      return (dup_pipe(node));
    }
  else if (dup_redir(node) == 1)
    {
      return (1);
    }
  return (0);
}
