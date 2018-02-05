/*
** close_pipes.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/execution/redirections
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Mon May 30 19:23:23 2016 Anthony LECLERC
** Last update Wed Jun  8 21:13:31 2016 teisse_m
*/

#include		<unistd.h>
#include		"types/struct_bintree.h"

void			close_pipes(t_binary_node *root, t_data *info)
{
  if (root->left == NULL)
    return ;
  if (root->right == NULL)
    return ;
  if (root->operator == L_PIPE)
    {
      close(root->iofd[0]);
      close(root->iofd[1]);
    }
  if (IS_OUTPUT(root->operator) && root->iofd[1] != -1)
    close(root->iofd[1]);
  if (IS_INPUT(root->operator) && root->iofd[0] != -1)
    close(root->iofd[0]);
  close_pipes(root->left, info);
  close_pipes(root->right, info);
  if (info)
    {
      dup2(info->iofd[0], 0);
      dup2(info->iofd[1], 1);
    }
}
