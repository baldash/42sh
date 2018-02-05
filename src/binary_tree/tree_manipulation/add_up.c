/*
** add_up.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun  1 19:07:50 2016 Hugo Baldassin
** Last update Wed Jun  1 20:40:12 2016 Hugo Baldassin
*/

#include	"types/struct_bintree.h"

void		add_up(t_binary_build *trees, t_binary_node *node)
{
  node->left = trees->cur_list->root;
  trees->cur_list->root = node;
}
