/*
** is_separator.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/misc
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Thu May 12 19:19:11 2016 anthony
** Last update Sun Jun  5 22:45:11 2016 teisse_m
*/

#include	<stddef.h>
#include	<stdbool.h>

bool		is_separator(char c, const char *separator)
{
  if (separator == NULL)
    return (false);
  while (*separator)
    {
      if (c == *separator)
	return (true);
      separator++;
    }
  return (false);
}
