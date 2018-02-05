/*
** add_right_redir.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun  1 23:08:36 2016 Hugo Baldassin
** Last update Thu Jun 02 04:25:04 2016 Anthony LECLERC
*/

#include	"types/struct_bintree.h"
#include	"prototypes/bintree_functions.h"
#include	"execution.h"
#include	"parser.h"
#include	"lexer.h"

int		add_right_redir(t_binary_build *trees, char *elem, t_lex type)
{
  t_binary_node	*new;

  (void)elem;
  if (!(new = new_node(NULL, NULL, type)))
    return (-1);
  if (trees->main_node->operator == L_PIPE)
    add_down_right(trees, new);
  else
    add_up(trees, new);
  trees->main_node = new;
  if (type == L_RDRIGHT)
    new->op_function = double_right_redir;
  else
    new->op_function = direct_right_redir;
  return (0);
}
