/*
** get_or_pipe.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing/lexer
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu May 26 18:09:59 2016 Anthony LECLERC
** Last update Fri May 27 03:33:20 2016 Anthony LECLERC
*/

int		get_pipe(const char *s)
{
  if (*s == '|')
    return (1);
  return (0);
}

int		get_or(const char *s)
{
  if (get_pipe(s))
    {
      if (get_pipe(s + 1))
	return (1);
    }
  return (0);
}
