/*
** direct_right_redir.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/execution
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Tue May 31 06:09:47 2016 Anthony LECLERC
** Last update Thu Jun  9 13:07:57 2016 Hugo Willaume
*/

#include		<stdio.h>
#include		<string.h>
#include		<errno.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/stat.h>
#include		<sys/types.h>
#include		<fcntl.h>
#include		"types/struct_bintree.h"
#include		"data.h"
#include		"execution.h"

int			double_right_redir(t_binary_node *node, t_data **info)
{
  (void)info;
  if ((node->iofd[1] = open(node->right->file,
			    O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
    {
      fprintf(stderr, "%s: %s\n",node->right->file, strerror(errno));
      return (1);
    }
  node->cmd = node->left->cmd;
  node->left->cmd = NULL;

  dup2(node->iofd[1], 1);

  return (0);
}

int			direct_right_redir(t_binary_node *node, t_data **info)
{
  (void)info;
  if ((node->iofd[1] = open(node->right->file,
			    O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
    {
      fprintf(stderr, "%s: %s\n",node->right->file, strerror(errno));
      return (1);
    }
  node->cmd = node->left->cmd;
  node->left->cmd = NULL;
  dup2(node->iofd[1], 1);
  return (0);
}
