/*
** buf_free.c for 42sh in /home/baldas/Prog/test
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun  2 01:48:52 2016 Hugo Baldassin
** Last update Sat Jun  4 20:52:25 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"get_next_line.h"

void		buf_free(int flag, char **line, char **buf)
{
  if (line_len(*line) == 0 || flag == 1)
    {
      free(*line);
      free(*buf);
      *line = NULL;
      *buf = NULL;
    }
}
