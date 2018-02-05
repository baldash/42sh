/*
** get_word.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing/lexer
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu May 26 17:46:12 2016 Anthony LECLERC
** Last update Fri May 27 03:25:16 2016 Anthony LECLERC
*/

#include	"misc.h"

int		is_word(const char *s)
{
  if (IS_CHAR(*s, "|<>;&") || *s == 0)
    return (0);
  return (1);
}
