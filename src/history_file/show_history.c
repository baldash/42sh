/*
** show_history.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/BONUS_Malex/history_file
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Thu Jun  2 14:44:07 2016 teisse_m
** Last update Thu Jun  9 05:21:16 2016 Anthony LECLERC
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	"misc.h"
#include	"history.h"
#include	"data.h"
#include	"get_next_line.h"

char		*last_history(t_data *info, char **input)
{
  int		i;
  int		j;
  char		*ret;

  j = 0;
  (void)input;
  i = info->history.history_size - 1;
  while (i > 0 && info->history.history_tab[i] == NULL)
    i--;
  while (info->history.history_tab[i][j] != '\0')
    {
      if (info->history.history_tab[i][j] >= 127)
	return (NULL);
      j++;
    }
  if (i <= 0 || info->history.history_tab[i] == NULL)
    return (NULL);
  if ((ret = strdup(info->history.history_tab[i])) == NULL)
    perror("strdup");
  return (ret);
}

int		show_history(t_data *info, char **input)
{
  int		i;

  i = 0;
  if (isatty(0) != 0)
    {
      if (input[1] != NULL && input[2] != NULL)
	return (put_error("fc: too many arguments\n"));
      if (input[1] != NULL && strcmp(input[1], "-c") == 0)
	{
	  clear_history(info);
	  return (0);
	}
      if (info->history.history_tab[i] == NULL)
	return (put_error("The history is empty\n"));
      while (i < (info->history.history_size - 1)
	     && info->history.history_tab[i] != NULL)
	printf("%s\n", info->history.history_tab[i++]);
    }
  return (0);
}
