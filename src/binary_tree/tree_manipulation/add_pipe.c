/*
** add_pipe.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun  1 18:37:43 2016 Hugo Baldassin
** Last update Thu Jun 02 04:16:19 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"execution.h"
#include	"types/struct_bintree.h"
#include	"prototypes/bintree_functions.h"
#include	"lexer.h"
#include	"parser.h"

int		add_pipe(t_binary_build *trees, char *elem, t_lex type)
{
  t_binary_node	*new;

  (void)elem;
  if (!(new = new_node(NULL, NULL, type)))
    return (-1);
  add_up(trees, new);
  trees->main_node = new;
  new->op_function = pipe_exec;
  return (0);
}
