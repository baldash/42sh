/*
** globing.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/TEST
** 
** Made by teisse_m
** Login   <teisse_m@epitech.net>
** 
** Started on  Sat Jun  4 20:29:05 2016 teisse_m
** Last update Sun Jun  5 22:10:42 2016 teisse_m
*/

#include	<glob.h>
#include	<stdio.h>
#include	<errno.h>

int		globing(int ac, char **av)
{
  glob_t	glb;
  int		ret;
  int		i;

  i = 0;
  if (ac < 1)
    return (2);
  ret = glob(av[1], 0, NULL, &glb);
  if (ret == 0)
    {
      while (glb.gl_pathv[i] != NULL)
	{
	  printf("%s ", glb.gl_pathv[i]);
	  i++;
	}
      printf("\n");
    }
  return (0);
}
