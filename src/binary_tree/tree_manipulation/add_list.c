/*
** add_list.c for  in /home/anthony/documents/repository/PSU_2015_42sh/src/binary_tree/tree_manipulation
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Wed Jun  1 22:14:28 2016 Anthony LECLERC
** Last update Fri Jun  3 19:55:49 2016 Sylvain Chaugny
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"types/struct_bintree.h"
#include	"prototypes/bintree_functions.h"
#include	"parser.h"
#include	"lexer.h"
#include	"execution.h"
#include	"misc.h"

static void	set_exec_check(t_binary_list *list, t_lex type)
{
  if (type == L_COMMA)
    {
      list->error_status = 0;
      list->check_if_exec = comma_check;
    }
  if (type == L_AND)
    {
      list->error_status = 1;
      list->check_if_exec = and_check;
    }
  if (type == L_OR)
    {
      list->error_status = 0;
      list->check_if_exec = or_check;
    }
}

int		add_list(t_binary_build *trees, char *elem, t_lex type)
{
  (void)elem;
  if (trees->cur_cmd != NULL && trees->main_node != NULL)
    {
      trees->cur_list->next = calloc(1, sizeof(t_binary_list));
      if (trees->cur_list->next == NULL)
	{
	  my_perror("Error: malloc failed at binary tree initialization\n");
	  return (-1);
	}
      trees->cur_list = trees->cur_list->next;
      set_exec_check(trees->cur_list, type);
      trees->cur_cmd = NULL;
      trees->main_node = NULL;
    }
  return (0);
}
