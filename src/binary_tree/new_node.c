/*
** new_node.c for anthony in /home/anthony/documents/repository/PSU_2015_minishell2/src/binary_tree
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Apr 09 22:21:27 2016 anthony
** Last update Sun Jun  5 22:17:43 2016 Gabriel Forteville
*/

#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>
#include		"types/struct_bintree.h"
#include		"misc.h"

static int		alloc_args(t_binary_node *node,
				   const char *cmd)
{
  node->cmd = malloc(2 * sizeof(char *));
  if (node->cmd == NULL)
    {
      my_perror("Error: malloc failed at binary tree initialization");
      return (1);
    }
  if ((node->cmd[0] = strdup(cmd)) == NULL)
    {
      my_perror("Error: strup failed\n");
      return (1);
    }
  node->cmd[1] = NULL;
  return (0);
}

static int 		alloc_strings_in_node(t_binary_node *new,
					      const char *cmd,
					      const char *file)
{
  if (cmd != NULL)
    {
      if (alloc_args(new, cmd))
	return (1);
    }
  else if (file != NULL)
    {
      new->file = strdup(file);
      if (new->file == NULL)
	{
	  my_perror("strdup :");
	  return (1);
	}
    }
  return (0);
}

t_binary_node		*new_node(const char *file,
				  const char *cmd,
				  t_lex type)
{
  t_binary_node		*new;

  new = calloc(1, sizeof(t_binary_node));
  if (new == NULL)
    {
      my_perror("Error: malloc failed at binary tree initialization");
      return (NULL);
    }
  if (alloc_strings_in_node(new, cmd, file))
    {
      free(new);
      return (NULL);
    }
  new->operator = type;
  new->iofd[0] = -1;
  new->iofd[1] = -1;
  return (new);
}
