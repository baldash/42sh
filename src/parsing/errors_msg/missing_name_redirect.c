/*
** missing_name_redirect.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing/errors_msg
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Mon May 30 13:36:43 2016 Anthony LECLERC
** Last update Sun Jun  5 19:59:24 2016 Sylvain Chaugny
*/

#include		<stdio.h>
#include		"prototypes/errors_parsing.h"

int			missing_name_redirect()
{
  if (fprintf(stderr, "Missing name for redirect.\n") <= 0)
    return (2);
  return (1);
}
