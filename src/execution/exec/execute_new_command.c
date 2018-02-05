/*
** execute_new_command.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 15:19:37 2016 Hugo Willaume
** Last update Thu Jun  9 11:12:33 2016 Sylvain Chaugny
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"prototypes/bintree_functions.h"
#include		"execution.h"
#include		"struct_bintree.h"

int			execute_new_command(t_binary_build *build, t_data *info)
{
  info->is_exited = 0;
  info->iofd[0] = dup(0);
  info->iofd[1] = dup(1);
  if (build->first_list != NULL)
    exec_binary_tree(build->first_list, &info);
  dup2(info->iofd[0], 0);
  close(info->iofd[0]);
  dup2(info->iofd[1], 1);
  close(info->iofd[1]);
  free_binary_tree(build->first_list);
  if (info->is_exited == 1)
    {
      fprintf(stdout, "exit\n");
      return (info->exit_value);
    }
  return (-1);
}
