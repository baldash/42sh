/*
** get_comma.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing/lexer
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu May 26 18:11:31 2016 Anthony LECLERC
** Last update Fri May 27 03:21:11 2016 Anthony LECLERC
*/

int		get_end(const char *s)
{
  if (*s == '\0')
    return (1);
  return (0);
}

int		get_comma(const char *s)
{
  if (*s == ';')
    return (1);
  return (0);
}
