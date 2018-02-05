/*
** reset_gnl.c for 42sh in /home/baldas/Prog/test
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Sat Jun  4 17:16:47 2016 Hugo Baldassin
** Last update Sat Jun  4 21:00:59 2016 Hugo Baldassin
*/

#include	<stdlib.h>

int		reset_gnl(int flag, char **line, char **buf)
{
  if (flag == 1)
    {
      free(*buf);
      if (!(*buf = malloc(1 * sizeof(char))))
	return (0);
      *buf[0] = '\0';
      *line = NULL;
      return (0);
    }
  return (1);
}
