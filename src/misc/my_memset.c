/*
** my_memset.c for 42sh in /home/anthony/documents/repository/PSU_2015_minishell2/src/misc
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Apr 09 22:29:24 2016 anthony
** Last update Sun Jun  5 22:45:37 2016 teisse_m
*/

#include		<stddef.h>

void			*my_memset(void *_mem, size_t size_bloc,
				   char value)
{
  char			*mem;

  mem = _mem;
  while (size_bloc > 0)
    {
      size_bloc--;
      mem[size_bloc] = value;
    }
  return (mem);
}
