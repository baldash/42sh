/*
** update.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/BONUS_Malex/history_file
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Wed Jun  1 20:49:34 2016 teisse_m
** Last update Wed Jun  8 21:39:13 2016 teisse_m
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<glob.h>
#include	<malloc.h>
#include	"data.h"
#include	"get_next_line.h"
#include	"misc.h"
#include	"history.h"

int		clear_history(t_data *info)
{
  int		fd;
  int		i;

  if ((fd = open(info->history.path, O_WRONLY | O_TRUNC | O_CREAT,
		 S_IRUSR | S_IRGRP | S_IWUSR | S_IWGRP)) < 0)
    return (put_error("Error: Open failed in function get_fd_history\n"));
  close(fd);
  i = 0;
  while (i < info->history.history_size
	 && info->history.history_tab[i] != NULL)
    {
      info->history.history_tab[i] = NULL;
      i++;
    }
  return (0);
}

int		update(char *cmd, t_history *history)
{
  int		fd;
  int		i;
  char		*tmp;

  if (isatty(0) != 0)
    {
      if (strcmp((tmp = epur_str(cmd)), "history") == 0
	  || strcmp(tmp, " ") == 0 || strcmp(tmp, "\0") == 0 || tmp[0] == '!'
	  || strcmp(tmp, "history -c") == 0)
	{
	  free(tmp);
	  return (0);
	}
      free(tmp);
      i = -1;
      while (++i < history->history_size && history->history_tab[i] != NULL);
      if (i < history->history_size && history->history_tab[i] == NULL)
	history->history_tab[i] = my_strdup(cmd);
    }
  return (0);
}

int		init_history(t_history *history)
{
  int		fd;
  int		i;
  char		*hist;

  i = 0;
  if ((fd = open(history->path, O_RDONLY)) >= 0)
    {
      while (i < history->history_size
	     && (hist = get_next_line(fd, 0)) != NULL)
	{
	  history->history_tab[i] = strdup(hist);
	  i++;
	  free(hist);
	}
      hist = get_next_line(0, 1);
      free(hist);
      close(fd);
    }
  while (i < history->history_size)
    history->history_tab[i++] = NULL;
  return (0);
}

int		get_path_history(t_history *history)
{
  glob_t	glb;
  int		ret;

  if (isatty(0) != 0)
    {
      ret = glob("~", GLOB_TILDE, NULL, &glb);
      if (ret == 0)
	history->path = modif_strcat(glb.gl_pathv[0], "/.42sh_history");
      if ((history->history_tab = malloc(sizeof(char *) *
					 (history->history_size + 1))) == NULL)
	return (put_error
		("Error: Malloc failed in function get_path_history\n"));
      init_history(history);
      globfree(&glb);
    }
  return (0);
}
