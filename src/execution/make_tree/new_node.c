/*
** new_node.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/temp/execution
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Tue May 31 17:16:35 2016 teisse_m
** Last update Sun Jun  5 22:18:54 2016 Gabriel Forteville
*/

#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>
#include		"types/struct_bintree.h"

static int		alloc_args(t_binary_node *node,
				   const char *args[],
				   size_t nb_args)
{
  size_t		i;

  i = 0;
  node->cmd = malloc((nb_args + 1) * sizeof(char *));
  if (node->cmd == NULL)
    {
      my_perror("Erreur:");
      return (1);
    }
  while (i < nb_args)
    {
      if ((node->cmd[i] = strdup(args[i])) == NULL)
	{
	  my_perror("Erreur:");
	  return (1);
	}
      i++;
    }
  node->cmd[i] = NULL;
  return (0);
}

static int 		alloc_strings_in_node(t_binary_node *new,
					      const char *args[],
					      const char *file,
					      size_t nb_arg)
{
  if (args != NULL)
    {
      if (alloc_args(new, args, nb_arg))
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
				  const char *args[],
				  size_t nb_arg,
				  t_lex type)
{
  t_binary_node		*new;

  new = calloc(1, sizeof(t_binary_node));
  if (new == NULL)
    {
      my_perror("Erreur:");
      return (NULL);
    }
  if (alloc_strings_in_node(new, args, file, nb_arg))
    {
      free(new);
      return (NULL);
    }
  new->operator = type;
  new->iofd[0] = 0;
  new->iofd[1] = 1;
  return (new);
}
