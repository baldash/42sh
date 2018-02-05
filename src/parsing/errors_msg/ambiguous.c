/*
** ambiguous.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing/errors_msg
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Mon May 30 13:27:37 2016 Anthony LECLERC
** Last update Sun Jun  5 19:59:50 2016 Sylvain Chaugny
*/

#include		<stdio.h>
#include		"prototypes/errors_parsing.h"

int			ambiguous_input_redirect()
{
  if (fprintf(stderr, "Ambiguous input redirect.\n") <= 0)
    return (2);
  return (1);
}

int			ambiguous_output_redirect()
{
  if (fprintf(stderr, "Ambiguous output redirect.\n") <= 0)
    return (2);
  return (1);
}
