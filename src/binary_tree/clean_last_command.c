/*
** clean_last_command.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/binary_tree
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu Jun 02 11:04:53 2016 Anthony LECLERC
** Last update Thu Jun 02 12:08:44 2016 Anthony LECLERC
*/

#include		<stdlib.h>
#include		"types/struct_bintree.h"

void			clean_last_command(t_binary_build *trees)
{
  t_binary_list		*new_last;

  new_last = trees->first_list;
  if (trees->cur_list == trees->first_list)
    {
      free(trees->first_list);
      trees->first_list = NULL;
    }
  else
    {
      while (new_last->next != trees->cur_list)
	new_last = new_last->next;
      free(new_last->next);
      new_last->next = NULL;
    }
}
