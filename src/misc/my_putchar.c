/*
** my_putchar.c for 42sh in /home/hurlu/rendu/PSU_2015_42sh/src
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 20:37:49 2016 Hugo Willaume
** Last update Sun Jun  5 22:46:13 2016 teisse_m
*/

#include	<unistd.h>
#include	"misc.h"

int		my_putchar(const char c)
{
  if (write (1, &c, 1) != 0)
    return (1);
  return (0);
}
