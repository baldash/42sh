/*
** is_string_word.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Thu May 12 19:13:42 2016 anthony
** Last update Sun Jun  5 22:53:39 2016 teisse_m
*/

#include		"misc.h"

bool			is_word(const char *s, const char *separator)
{
  while (*s || !is_separator(*s, separator))
    {
      if (!is_alpha(*s))
	return (false);
      s++;
    }
  return (true);
}
