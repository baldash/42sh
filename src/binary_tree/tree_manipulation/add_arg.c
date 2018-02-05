/*
** add_arg.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun  1 20:09:15 2016 Hugo Baldassin
** Last update Sun Jun  5 13:37:01 2016 Sylvain Chaugny
*/

#include	<stdlib.h>
#include	<string.h>
#include	"types/struct_bintree.h"
#include	"misc.h"

static char	**cpy_args(t_binary_node *node, const char *arg)
{
  char		**new_args;
  int		y;

  y = my_tablen(node->cmd);
  if ((new_args = realloc(node->cmd, (y + 2) * sizeof(char *))) == NULL)
    return (NULL);
  if ((new_args[y] = strdup(arg)) == NULL)
    return (NULL);
  new_args[y + 1] = NULL;
  return (new_args);
}

int		add_arg(t_binary_build *trees, char *arg, t_lex type)
{
  char		**new_args;

  (void)type;
  if (!(new_args = cpy_args(trees->cur_cmd, arg)))
    return (-1);
  trees->cur_cmd->cmd = new_args;
  return (0);
}
