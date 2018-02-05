/*
** my_strcat.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/BONUS_Malex
** 
** Made by teisse_m
** Login   <teisse_m@epitech.net>
** 
** Started on  Fri Jun  3 12:36:18 2016 teisse_m
** Last update Fri Jun  3 20:59:31 2016 teisse_m
*/

#include	<unistd.h>
#include	<malloc.h>
#include	"misc.h"

char		*modif_strcat(char *s1, char *s2)
{
  int		i;
  int		j;
  char		*tmp;

  j = 0;
  i = 0;
  if (s1 == NULL && s2 == NULL)
    return (NULL);
  if (s1 == NULL && s2 != NULL)
    return (s2);
  if (s2 == NULL && s1 != NULL)
    return (s1);
  if ((tmp = malloc(sizeof(char) *
		    (my_strlen(s1) + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  while (i < my_strlen(s1))
    tmp[j++] = s1[i++];
  i = 0;
  while (i < my_strlen(s2))
    tmp[j++] = s2[i++];
  tmp[j] = '\0';
  return (tmp);
}
