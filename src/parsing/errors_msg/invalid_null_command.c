/*
** invalid_null_command.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing/errors_msg
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Mon May 30 13:35:32 2016 Anthony LECLERC
** Last update Sun Jun  5 19:59:36 2016 Sylvain Chaugny
*/

#include		<stdio.h>
#include		"prototypes/errors_parsing.h"

int			invalid_null_command()
{
  if (fprintf(stderr, "Invalid null command.\n") <= 0)
    return (2);
  return (1);
}
