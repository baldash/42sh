/*
** check_error_status.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/temp/execution
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Tue May 31 17:12:16 2016 teisse_m
** Last update Sun Jun  5 20:01:27 2016 Sylvain Chaugny
*/

#include		<unistd.h>
#include		<stdio.h>
#include		<sys/types.h>
#include		<sys/wait.h>

void			check_error_status(int status)
{
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == 11)
	if (fprintf(stderr, "Segmentation fault\n") <= 0)
	  return ;
    }
}
