/*
** cut_history.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Sat Jun  4 03:26:22 2016 teisse_m
** Last update Thu Jun  9 11:15:05 2016 Sylvain Chaugny
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include        <stdio.h>
#include        <string.h>
#include	<malloc.h>
#include        "misc.h"
#include        "data.h"
#include        "wordtab.h"

void		free_hist(t_data *info)
{
  int		y;

  y = 0;
  if (info->history.history_tab != NULL)
    {
      while (y < info->history.history_size
	     && info->history.history_tab[y] != NULL)
	{
	  free(info->history.history_tab[y]);
	  y++;
	}
      free(info->history.history_tab);
    }
}

int		finish_history(t_data *info)
{
  int		fd;
  int		i;
  int		j;

  i = 0;
  if ((fd = open(info->history.path, O_WRONLY | O_TRUNC | O_CREAT,
                 S_IRUSR | S_IRGRP | S_IWUSR | S_IWGRP)) < 0)
    return (put_error("Error: Open failed in function finished_history\n"));
  while (i < (info->history.history_size - 1)
  	 && info->history.history_tab[i] != NULL)
    {
      j = -1;
      while (info->history.history_tab && info->history.history_tab[i] &&
	     info->history.history_tab[i][++j] != '\0')
	if (info->history.history_tab[i][j] >= 127 ||
	    info->history.history_tab[i][j] < 0)
	  {
	    close(fd);
	    return (0);
	  }
      dprintf(fd, "%s\n", info->history.history_tab[i]);
      i++;
    }
  close(fd);
  return (0);
}

static char	*get_command_with_number(char **mem, int tmp, int i)
{
  char		*cmd;

  cmd = NULL;
  if (tmp <= i && mem[tmp] != NULL)
    {
      cmd = strdup(mem[tmp]);
      free_tab(mem);
      return (cmd);
    }
  free_tab(mem);
  return (NULL);
}

char		*cut_history(t_data *info, char *cmd)
{
  int		i;
  int		tmp;
  char		**mem;

  i = info->history.history_size - 1;
  if (is_num(cmd) == 2)
    return (NULL);
  while (i >= 0 && info->history.history_tab[i] == NULL)
    i--;
  if (i <= 0 || info->history.history_tab[i] == NULL)
    return (NULL);
  tmp = -1;
  while (info->history.history_tab[i][++tmp] != '\0')
    if (info->history.history_tab[i][tmp] >= 127)
      return (NULL);
  mem = my_str_to_wordtab(info->history.history_tab[i], " \t");
  i = 0;
  while (mem[i] != NULL)
    i++;
  tmp = my_getnbr(cmd, 0, 0);
  return (get_command_with_number(mem, tmp, i));
}
