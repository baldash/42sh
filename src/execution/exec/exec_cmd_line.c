/*
** exec_cmd_line.c for PSU_2015_minishell2 in /home/anthony/documents/repository/PSU_2015_minishell2/src/execution
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Fri May 06 04:16:01 2016 anthony
** Last update Sun Jun  5 15:20:17 2016 Sylvain Chaugny
*/

#include		<stdlib.h>
#include		"types/struct_bintree.h"
#include		"execution.h"
#include		"data.h"

int			exec_cmd_line(t_binary_node *root, t_data **info)
{
  int			prog_count;

  if (root->left == NULL && root->right == NULL)
    return (1);
  if ((prog_count = exec_cmd_line(root->left, info)) == -1)
    return (-1);
  if (exec_cmd_line(root->right, info) == -1)
    return (-1);
  if (root->op_function != NULL)
    {
      if (root->op_function(root, info))
	return (-1);
    }
  return (prog_count + 1);
}
