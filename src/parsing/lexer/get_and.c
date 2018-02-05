/*
** get_and.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing/lexer
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu May 26 18:19:18 2016 Anthony LECLERC
** Last update Fri May 27 19:03:44 2016 Hugo Baldassin
*/

int		get_and(const char *s)
{
  if (*s == '&')
    {
      if (*(s + 1) == '&')
	return (1);
    }
  return (0);
}
