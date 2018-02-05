/*
** add_file.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun  1 20:34:55 2016 Hugo Baldassin
** Last update Wed Jun  1 21:16:45 2016 Hugo Baldassin
*/

#include	"types/struct_bintree.h"
#include	"prototypes/bintree_functions.h"
#include	"parser.h"

int		add_file(t_binary_build *trees, char *elem, t_lex type)
{
  t_binary_node	*new;

  if (!(new = new_node(elem, NULL, type)))
    return (-1);
  add_down_right(trees, new);
  return (0);
}
