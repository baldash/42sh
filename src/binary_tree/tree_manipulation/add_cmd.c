/*
** add_cmd.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun  1 19:46:25 2016 Hugo Baldassin
** Last update Wed Jun  1 21:08:05 2016 Hugo Baldassin
*/

#include	"types/struct_bintree.h"
#include	"prototypes/bintree_functions.h"
#include	"lexer.h"
#include	"parser.h"

void		add_downer_left(t_binary_build *trees, t_binary_node *node)
{
  t_binary_node	*tmp;

  tmp = trees->main_node;
  while (tmp->left)
    tmp = tmp->left;
  tmp->left = node;
}

int		add_cmd(t_binary_build *trees, char *elem, t_lex type)
{
  t_binary_node	*new;

  if (!(new = new_node(NULL, elem, type)))
    return (-1);
  if (trees->main_node->operator == L_PIPE)
    add_down_right(trees, new);
  else
    add_downer_left(trees, new);
  trees->cur_cmd = new;
  return (0);
}
