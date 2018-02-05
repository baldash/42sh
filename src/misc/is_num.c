/*
** is_num.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh
** 
** Made by teisse_m
** Login   <teisse_m@epitech.net>
** 
** Started on  Fri Jun  3 22:17:00 2016 teisse_m
** Last update Fri Jun  3 22:41:25 2016 teisse_m
*/

#include	<string.h>

int		my_getnbr(char *str, int i, int mem)
{
  int		n;
  int		l;

  n = strlen(str);
  if (i >= n)
    return (mem);
  else
    {
      l = (str[i] - 48);
      mem *= 10;
      mem += l;
      i++;
      return (my_getnbr(str, i, mem));
    }
}

int		alpha_num(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < 'a' || str[i] > 'z') &&
	  (str[i] < 'A' || str[i] > 'Z') &&
	  (str[i] < '0' || str[i] > '9'))
	return (2);
      i++;
    }
  return (0);
}

int		is_num(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (2);
    }
  return (0);
}
