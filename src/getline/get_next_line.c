/*
** get_next_line.c for 42sh in /home/baldas/Prog/test
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Sat Jun  4 16:57:13 2016 Hugo Baldassin
** Last update Sat Jun  4 20:51:05 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"get_next_line.h"

int		line_check(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

size_t		line_len(char *str)
{
  if (str == NULL)
    return (0);
  return (strlen(str));
}

void		epur_line(char *line, char *buf)
{
  int		i;
  int		j;
  int		len;

  i = 0;
  j = 0;
  len = line_len(line);
  if (line == NULL)
    return ;
  while (line[i] != '\n' && line[i] != '\0')
    i++;
  line[i] = '\0';
  if (i < len)
    {
      i++;
      while (line[i] != '\0')
	buf[j++] = line[i++];
    }
  buf[j] = '\0';
}

char		*my_strcat(char *line, char *buf)
{
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  if (!(res = malloc((line_len(line) + line_len(buf) + 1) * sizeof(char))))
    return (NULL);
  while (line != NULL && line[i] != '\0')
    {
      res[i] = line[i];
      i++;
    }
  while (buf[j] != '\0')
    {
      res[i + j] = buf[j];
      j++;
    }
  res[i + j] = '\0';
  free(line);
  return (res);
}

char		*get_next_line(int fd, int flag)
{
  static char	*buf = NULL;
  char		*line;
  int		len;

  if (buf == NULL)
    {
      if (!(buf = malloc((READ_SIZE + 1) * sizeof(char))))
	return (NULL);
      buf[0] = '\0';
    }
  len = reset_gnl(flag, &line, &buf);
  line = NULL;
  line = my_strcat(line, buf);
  while (line_check(buf) == 0 && len != 0)
    {
      len = read(fd, buf, READ_SIZE);
      if (len == -1)
	return (NULL);
      buf[len] = '\0';
      line = my_strcat(line, buf);
    }
  buf_free(flag, &line, &buf);
  epur_line(line, buf);
  return (line);
}
