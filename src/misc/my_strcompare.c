/*
** my_strcompare.c for 42sh in /home/fortevg/rendu/PSU/PSU_2015_42sh/src/misc
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri May 20 17:35:21 2016 Forteville Gabriel
** Last update Sun Jun  5 22:47:01 2016 teisse_m
*/

#include	"bool.h"
#include	"misc.h"

int		my_strcompare(char *src1, char *src2)
{
  int		index;

  index = 0;
  while (src1[index] == src2[index] && src1[index] != 0 && src2[index] != 0)
    index++;
  if (index == my_strlen(src1) &&
      index == my_strlen(src2))
    return (TRUE);
  return (FALSE);
}
