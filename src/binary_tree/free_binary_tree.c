/*
** free_binary_tree.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/binary_tree
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Wed Jun 01 23:18:09 2016 Anthony LECLERC
** Last update Wed Jun 01 23:30:02 2016 Anthony LECLERC
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"types/struct_bintree.h"
#include		"misc.h"

void			free_list_nodes(t_binary_node *node)
{
  if (node->right != NULL)
    free_list_nodes(node->right);
  if (node->left != NULL)
    free_list_nodes(node->left);
  free(node->file);
  free_tab(node->cmd);
  free(node);
}

void			free_binary_tree(t_binary_list *tree)
{
  if (tree != NULL)
    {
      if (tree->root != NULL)
	free_list_nodes(tree->root);
      free_binary_tree(tree->next);
      free(tree);
    }
}
