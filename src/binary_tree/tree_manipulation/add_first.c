/*
** add_first.c for 42h in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun  1 21:49:51 2016 Hugo Baldassin
** Last update Sun Jun  5 15:25:25 2016 teisse_m
*/

#include	<stdlib.h>
#include	"types/struct_bintree.h"
#include	"prototypes/bintree_functions.h"
#include	"execution.h"
#include	"lexer.h"

static const	t_op_function	g_get_function[] =
  {
    NULL,
    double_left_redir,
    direct_left_redir,
    double_right_redir,
    direct_right_redir,
    NULL,
    NULL,
    pipe_exec,
    NULL,
    NULL
  };

int		add_first(t_binary_build *trees, char *elem, t_lex type)
{
  t_binary_node	*new;

  if (type == L_WORD)
    {
      if (!(new = new_node(NULL, elem, type)))
	return (-1);
    }
  else
    {
      if (!(new = new_node(NULL, NULL, type)))
	return (-1);
      new->op_function = g_get_function[type];
    }
  trees->cur_list->root = new;
  trees->main_node = new;
  if (type == L_WORD)
    trees->cur_cmd = new;
  return (0);
}
