/*
** add_down_right.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun  1 19:23:09 2016 Hugo Baldassin
** Last update Wed Jun 01 21:58:12 2016 Anthony LECLERC
*/

#include	"types/struct_bintree.h"

void		add_down_right(t_binary_build *trees, t_binary_node *node)
{
  node->left = trees->main_node->right;
  trees->main_node->right = node;
}
