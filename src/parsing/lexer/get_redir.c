/*
** get_redir.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing/lexer
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu May 26 17:48:30 2016 Anthony LECLERC
** Last update Thu May 26 18:09:41 2016 Anthony LECLERC
*/

int		get_rleft(const char *s)
{
  if (*s == '<')
    return (1);
  return (0);
}

int		get_rright(const char *s)
{
  if (*s == '>')
    return (1);
  return (0);
}

int		get_rdright(const char *s)
{
  if (get_rright(s))
    {
      if (get_rright(s + 1))
	return (1);
    }
  return (0);
}

int		get_rdleft(const char *s)
{
  if (get_rleft(s))
    {
      if (get_rleft(s + 1))
	return (1);
    }
  return (0);
}
