/*
** epur_str.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/BONUS_Malex
** 
** Made by teisse_m
** Login   <teisse_m@epitech.net>
** 
** Started on  Fri Jun  3 13:16:27 2016 teisse_m
** Last update Sun Jun  5 22:44:15 2016 teisse_m
*/

#include	<stdlib.h>
#include	"misc.h"

char		*epur_str(char *str)
{
  char		*tmp;
  int		i;
  int		k;

  i = 0;
  k = 0;
  if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      tmp[k++] = str[i++];
      while ((str[i] == ' ') || (str[i] == '\t'))
	i++;
      if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (str[i] != '\0'))
	{
	  tmp[k] = ' ';
	  k++;
	}
    }
  tmp[k] = '\0';
  return (tmp);
}
