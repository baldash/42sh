/*
** find_in_history.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/history_file
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Fri Jun  3 21:45:07 2016 teisse_m
** Last update Thu Jun  9 05:19:39 2016 Anthony LECLERC
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	"misc.h"
#include	"data.h"

char		*find_min(t_data *info, char *cmd)
{
  int		i;
  int		tmp;
  char		*ret;

  i = 0;
  if (cmd[i] == '\0')
    return (NULL);
  if (is_num(&cmd[i]) == 2)
    return (NULL);
  i = my_getnbr(cmd, 0, 0);
  tmp = info->history.history_size - 1;
  while (tmp >= 0 && info->history.history_tab[tmp] == NULL)
    tmp--;
  if (tmp - i < -1)
    return (NULL);
  i = tmp - i + 1;
  tmp = -1;
  while (info->history.history_tab[i][++tmp] != '\0')
    if (info->history.history_tab[i][tmp] >= 127)
      return (NULL);
  if ((ret = strdup(info->history.history_tab[i])) == NULL)
    perror("strdup");
  return (ret);
}

char		*get_pos_in_history(char *pos, t_data *info)
{
  int		pos_tab;
  int		tmp;

  tmp = 0;
  if (is_num(&pos[tmp]) == 2)
    return (NULL);
  pos_tab = my_getnbr(pos, 0, 0);
  pos_tab--;
  if (pos_tab < info->history.history_size && pos_tab >= 0
      && info->history.history_tab[pos_tab] != NULL)
    {
      tmp = -1;
      while (info->history.history_tab[pos_tab][++tmp] != '\0')
	if (info->history.history_tab[pos_tab][tmp] >= 127)
	  return (NULL);
    }
  else
    return (NULL);
  return (info->history.history_tab[pos_tab]);
}

char		*compare_history_string(char *cmd, t_data *info)
{
  int		i;
  int		tmp;

  i = info->history.history_size - 1;
  while (i >= 0 && info->history.history_tab[i] == NULL)
    i--;
  while (i >= 0 && strncmp(cmd, info->history.history_tab[i], strlen(cmd)))
    i--;
  if (i >= 0 && info->history.history_tab[i] != NULL)
    {
      tmp = -1;
      while (info->history.history_tab[i][++tmp] != '\0')
	if (info->history.history_tab[i][tmp] >= 127)
	  return (NULL);
      return (info->history.history_tab[i]);
    }
  return (NULL);
}

char		*find_a_command(t_data *info, char *cmd)
{
  int		i;
  char		*tmp;

  i = 0;
  if (isatty(0) != 0)
    {
      if (strcmp(cmd, "!!") == 0)
	return (last_history(info, NULL));
      while (cmd[i] != '\0' && cmd[i] == '!')
	i++;
      if (i > 1 && cmd[2] != '\0' && cmd[2] == ':')
	if ((tmp = cut_history(info, &cmd[i + 1])) != NULL)
	  return (tmp);
      if (i > 1)
	return (NULL);
      if (cmd[i] != '\0' && cmd[i] == '-')
	return (find_min(info, &cmd[i + 1]));
      if (is_num(&cmd[i]) == 0)
	if ((tmp = get_pos_in_history(&cmd[i], info)) == NULL)
	  return (tmp);
      if (alpha_num(&cmd[i]) == 0)
	return (compare_history_string(&cmd[i], info));
    }
  return (NULL);
}
