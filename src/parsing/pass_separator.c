/*
** pass_separator.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Fri May 27 17:24:22 2016 Anthony LECLERC
** Last update Sun Jun  5 22:53:57 2016 teisse_m
*/

#include	"misc.h"

void		pass_separator(const char **s, const char *separator)
{
  while (**s != 0 && is_separator(**s, separator))
    (*s)++;
}
