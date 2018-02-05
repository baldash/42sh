/*
** exec_no_path.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/temp/execution
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Tue May 31 17:13:50 2016 teisse_m
** Last update Sun Jun  5 20:00:59 2016 Sylvain Chaugny
*/

#include	<string.h>
#include	<errno.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	"execution.h"
#include	"environnement.h"

void		aff_error_no_path(char *cmd)
{
  if (strcmp(strerror(errno), "No such file or directory") == 0)
    {
      if (fprintf(stderr, "%s: Command not found.\n", cmd) <= 0)
	return ;
    }
  else
    {
      if (fprintf(stderr, "%s: %s.\n", cmd, strerror(errno)) <= 0)
	return ;
    }
}

void		exec_no_path(char **cmd, char **env)
{
  execve(cmd[0], cmd, env);
  aff_error_no_path(cmd[0]);
  exit(1);
}
