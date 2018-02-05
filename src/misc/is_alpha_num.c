/*
** is_alpha_num.c for 42sh in /home/anthony/documents/repository/PSU_2015_minishell2/src/misc
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Fri Apr  1 16:19:57 2016 anthony
** Last update Sun Jun  5 22:44:45 2016 teisse_m
*/

#include		<stdbool.h>

bool			is_digit(char c)
{
  if (c >= '0' && c <= '9')
    return (true);
  return (false);
}

bool			is_alpha_capital(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (true);
  return (false);
}

bool			is_alpha_min(char c)
{
  if (c >= 'a' && c <= 'z')
    return (true);
  return (false);
}

bool			is_alpha(char c)
{
  return (is_alpha_capital(c) || is_alpha_min(c));
}

bool			is_alpha_num(char c)
{
  return (is_alpha(c) || is_digit(c));
}
