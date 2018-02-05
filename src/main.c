/*
** main.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu May 26 17:32:30 2016 Anthony LECLERC
** Last update Thu Jun  9 13:13:18 2016 Anthony LECLERC
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<string.h>
#include		<signal.h>
#include		<pwd.h>
#include		<stdbool.h>
#include		"get_next_line.h"
#include		"data.h"
#include		"misc.h"
#include		"history.h"
#include		"execution.h"
#include		"environnement.h"
#include		"parser.h"
#include		"line_edit.h"
#include		"types/struct_bintree.h"
#include		"prototypes/bintree_functions.h"

bool			g_prompt = true;

int			prompt(char *prompt)
{
  uid_t			uid;
  struct passwd		*username;
  char			*way;
  int			size;

  if (isatty(0) != 0)
    {
      if (prompt != NULL && strcmp(prompt, "\n") == 0)
	{
	  size = fprintf(stdout, "\n");
	  prompt = NULL;
	}
      if (prompt == NULL)
	{
	  uid = getuid();
	  username = getpwuid(uid);
	  way = getcwd(NULL, 0);
	  size = fprintf(stdout, "%s @ 42sh in %s> ", username->pw_name, way);
	  free(way);
	}
      else
	size = fprintf(stdout, "%s", prompt);
      fflush(stdout);
    }
  return (size);
}

void			control_c()
{
  g_prompt = false;
  prompt("\n");
}

int			handle_tty_mode(t_data *info)
{
  t_binary_build	build;

  prompt(NULL);
  while ((info->cmd = get_next_line(0, 0)) != NULL)
    {
      g_prompt = true;
      info->exit_value = 0;
      memset(&build, 0, sizeof(t_binary_build));
      if (llparser(info->cmd, NULL, &build) == 1)
	{
	  info->exit_value = 1;
	  free_binary_tree(build.first_list);
	}
      else if (execute_new_command(&build, info) != -1)
	return (info->exit_value);
      update(info->cmd, &(info->history));
      ((g_prompt == true) ? prompt(NULL) : (void)g_prompt);
      free(info->cmd);
    }
  return (info->exit_value);
}

int			main_loop(t_data *info, t_terminals *term, int error)
{
  t_binary_build	build;

  if (isatty(0) != 0 && error != 3)
    {
      if (signal(SIGINT, &control_c) == SIG_ERR)
	return (-1);
      return (line_edit_loop(info, term, &build));
    }
  return (handle_tty_mode(info));
}

int			main(int ac, char **av, char **env)
{
  t_data		info_shell;
  int			i;
  int			error;

  error = 0;
  (void)ac;
  (void)av;
  if (isatty(0) == 0)
    info_shell.terminal_mode = MODE_TTY;
  else
    info_shell.terminal_mode = MODE_TERMINAL;
  if ((error = init_shell(&info_shell, &(info_shell.terms), env)) != 0
      && error != 3)
    return (1);
  if (error == 3)
    info_shell.terminal_mode = MODE_TTY;
  i = main_loop(&info_shell, &(info_shell.terms), error);
  free_shell(&info_shell, &(info_shell.terms), error);
  return (i);
}
