/*
** error.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/temp/execution
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Tue May 31 17:01:17 2016 teisse_m
** Last update Sun Jun  5 22:20:12 2016 Gabriel Forteville
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"misc.h"

void		exit_error(char *str)
{
  my_perror(str);
  exit(1);
}

int		return_error(char *str)
{
  my_perror(str);
  return (1);
}
