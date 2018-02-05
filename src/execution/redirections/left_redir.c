/*
** left_redir.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/execution
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Tue May 31 07:46:16 2016 Anthony LECLERC
** Last update Thu Jun  9 13:05:15 2016 Sylvain Chaugny
*/

#include		<string.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/stat.h>
#include		<sys/types.h>
#include		<fcntl.h>
#include		<errno.h>
#include		"types/struct_bintree.h"
#include		"get_next_line.h"
#include		"misc.h"
#include		"data.h"
#include		"execution.h"

void			write_data_in_pipe(int		fd,
					   char		*s)
{
  dprintf(fd, "%s\n", s);
}

int			my_strcmp(char			*s1,
				  char			*s2)
{
  int			i;

  if (s1 == NULL || s2 == NULL)
    return (0);
  if (strlen(s1) != strlen(s2))
    return (0);
  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  if (i == (int)strlen(s1))
    return (1);
  return (0);
}

int			double_left_redir(t_binary_node	*node,
					  t_data	**info)
{
  char		*s;

  if (pipe(node->iofd) == -1)
    return (1);
  s = NULL;
  while (my_strcmp(node->right->file, s) == 0)
    {
      write(1, "? ", 2);
      (s != NULL) ? free(s) : (void)s;
      if ((s = (((*info)->terminal_mode == MODE_TTY) ? get_next_line(0, 0) :
		line_edition(&((*info)->terms.tty)))) == NULL)
	{
	  close(node->iofd[1]);
	  node->cmd = node->left->cmd;
	  node->left->cmd = NULL;
	  return (0);
	}
      if (my_strcmp(node->file, s) == 0)
	write_data_in_pipe(node->iofd[1], s);
    }
  close(node->iofd[1]);
  dup2(node->iofd[0], 0);
  node->cmd = node->left->cmd;
  node->left->cmd = NULL;
  return (0);
}

int			direct_left_redir(t_binary_node	*node,
					  t_data	**info)
{
  (void)info;
  node->cmd = node->left->cmd;
  node->left->cmd = NULL;
  if ((node->iofd[0] = open(node->right->file, O_RDONLY)) == -1)
    {
      write(2, node->right->file, strlen(node->right->file));
      fprintf(stderr, ": %s\n", strerror(errno));
      return (1);
    }
  dup2(node->iofd[0], 0);
  return (0);
}
