/*
** line_edit_loop.c for  in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 14:54:19 2016 Hugo Willaume
** Last update Sun Jun  5 23:05:32 2016 Sylvain Chaugny
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	"misc.h"
#include	"execution.h"
#include	"parser.h"
#include	"struct_bintree.h"
#include	"prototypes/bintree_functions.h"
#include	"line_edit.h"

extern bool	g_prompt;

int		line_edit_loop(t_data *info, t_terminals *term,
			       t_binary_build *build)
{
  init_cursor(&term->tty, prompt(NULL));
  while ((info->cmd = line_edition(&term->tty)) != NULL)
    {
      g_prompt = true;
      info->exit_value = -1;
      memset(build, 0, sizeof(t_binary_build));
      if (llparser(info->cmd, NULL, build) == 1)
	free_binary_tree(build->first_list);
      else if (execute_new_command(build, info) != -1)
	return (info->exit_value);
      update(info->cmd, &(info->history));
      if (g_prompt == true)
	init_cursor(&term->tty, prompt(NULL));
      free(info->cmd);
    }
  prompt("exit\n");
  return (0);
}
