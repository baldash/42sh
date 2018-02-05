/*
** add_down_left.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun  1 19:40:48 2016 Hugo Baldassin
** Last update Wed Jun 01 21:59:53 2016 Anthony LECLERC
*/

#include	"types/struct_bintree.h"
#include	"lexer.h"

void		add_down_left(t_binary_build *trees, t_binary_node *node)
{
  node->left = trees->main_node->left;
  trees->main_node->left = node;
  if (node->operator == L_WORD)
    trees->cur_cmd = node;
}
