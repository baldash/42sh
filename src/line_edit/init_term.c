/*
** init_term.c for 42sh  in /home/hurlu/rendu/PSU_2015_42sh
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sun Jun  5 13:57:50 2016 Hugo Willaume
** Last update Thu Jun  9 03:13:29 2016 Anthony LECLERC
*/

#include		<string.h>
#include		<unistd.h>
#include		<stdio.h>
#include		<errno.h>
#include		<sys/ioctl.h>
#include		<curses.h>
#include		<term.h>
#include		"misc.h"
#include		"line_edit.h"

static int		fill_capacities(t_tty *term, struct termios *termios)
{
  if (setupterm(NULL, 1, NULL) == ERR)
    {
      ioctl(0, TCSETS, termios);
      return (1);
    }
  my_putstr(tigetstr("smkx"));
  term->capacities[0] = tigetstr("kcub1");
  term->capacities[1] = tigetstr("kcuf1");
  term->capacities[2] = "\eb";
  term->capacities[3] = "\ef";
  term->capacities[4] = tigetstr("khome");
  term->capacities[5] = tigetstr("kend");
  term->capacities[6] = tigetstr("kdch1");
  term->capacities[7] = NULL;
  return (0);
}

void			init_cursor(t_tty *term, int prompt_size)
{
  term->cur_pos.x = prompt_size % term->width;
  term->cur_pos.y = term->width / prompt_size;
  term->prompt_size = term->cur_pos.x + 1;
}

int			init_term(t_tty *tty,
				  struct termios *term,
				  struct termios *new_term)
{
  struct winsize	win;

  if (ioctl(0, TCGETS, term) == -1 || ioctl(0, TCGETS, new_term) == -1)
    {
      fprintf(stderr, "ioctl: %s\n", strerror(errno));
      return (1);
    }
  new_term->c_lflag &= ~ICANON;
  new_term->c_lflag &= ~IUTF8;
  new_term->c_lflag &= ~ECHO;
  if (ioctl(0, TCSETS, new_term) == -1 || ioctl(0, TIOCGWINSZ, &win) == -1)
    {
      fprintf(stderr, "ioctl: %s\n", strerror(errno));
      return (1);
    }
  tty->height = win.ws_row;
  tty->width = win.ws_col;
  if (fill_capacities(tty, term) != 0)
    return (2);
  return (0);
}
