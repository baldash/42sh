/*
** exec_buitins.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/Builtins
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Tue Apr 12 19:26:16 2016 anthony
** Last update Thu Jun  9 04:57:23 2016 Anthony LECLERC
*/

#include	<string.h>
#include	<stdio.h>
#include	"environnement.h"
#include	"misc.h"
#include	"struct_bintree.h"
#include	"data.h"
#include	"wordtab.h"

void		init_builtins_structure(t_data *info)
{
  info->builtins[0].builtin = "cd";
  info->builtins[0].f = my_cd;
  info->builtins[1].builtin = "setenv";
  info->builtins[1].f = my_setenv;
  info->builtins[2].builtin = "unsetenv";
  info->builtins[2].f = my_unsetenv;
  info->builtins[3].builtin = "echo";
  info->builtins[3].f = echo;
  info->builtins[4].builtin = "history";
  info->builtins[4].f = show_history;
  info->builtins[5].builtin = "exit";
  info->builtins[5].f = my_exit;
}

int		is_there_pipes_or_redir(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (1);
  while (str[i])
    {
      if (str[i] == '>' || str[i] == '<' || str[i] == '|')
	return (1);
      i++;
    }
  return (0);
}

int		handle_history_research(t_binary_node **node,
					t_data *info)
{
  char		*tmp;

  if (info->history.history_tab[0] == NULL)
    {
      fprintf(stderr, "%s: Event not found.\n", (*node)->cmd[0]);
      return (1);
    }
  tmp = find_a_command(info, (*node)->cmd[0]);
  if (tmp != NULL)
    printf("%s\n", tmp);
  if (is_there_pipes_or_redir(tmp))
    {
      free(tmp);
      fprintf(stderr, "%s: Event not found.\n", (*node)->cmd[0]);
      return (1);
    }
  free_tab((*node)->cmd);
  (*node)->cmd = my_str_to_wordtab(tmp, " \t");
  free(tmp);
  return (0);
}

int		exec_builtins(t_binary_node **node,
			      t_data *info)
{
  int		i;

  i = -1;
  while (++i < 6)
    if (strcmp(info->builtins[i].builtin, (*node)->cmd[0]) == 0)
      {
	(info->builtins[i].f)(info, (*node)->cmd);
	return (1);
      }
  if ((*node)->cmd[0][0] == '!')
    {
      if (handle_history_research(node, info) == 1)
  	return (1);
      i = -1;
      while (++i < 6)
      	if (strcmp(info->builtins[i].builtin, (*node)->cmd[0]) == 0)
      	  {
      	    (info->builtins[i].f)(info, (*node)->cmd);
	    return (1);
      	  }
    }
  return (0);
}
