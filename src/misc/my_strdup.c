/*
** my_strdup.c for 42sh in /home/anthony/documents/repository/PSU_2015_minishell2/src/misc
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sun Apr 10 07:23:24 2016 anthony
** Last update Sun Jun  5 22:47:35 2016 teisse_m
*/

#include	<stdlib.h>
#include	"misc.h"

char		*my_strdup(const char *c)
{
  char		*dup;

  dup = malloc(my_strlen(c) + 1);
  if (dup == NULL)
    {
      my_perror("Malloc error in 'strdup'\n");
      return (NULL);
    }
  my_strcpy(dup, c);
  return (dup);
}
