/*
** check_if_exec.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/execution/exec
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Wed Jun 01 22:28:37 2016 Anthony LECLERC
** Last update Sun Jun  5 21:00:50 2016 Sylvain Chaugny
*/

#include		<stdbool.h>

bool			comma_check(int status)
{
  (void)status;
  return (true);
}

bool			and_check(int status)
{
  if (status == 0)
    return (true);
  return (false);
}

bool			or_check(int status)
{
  if (status != 0)
    return (true);
  return (false);
}
