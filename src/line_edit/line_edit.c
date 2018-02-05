/*
** line_edit.c for 42sh  in /home/hurlu/tests/parody_shell
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Wed Jun  1 11:24:00 2016 Hugo Willaume
** Last update Sun Jun  5 22:49:06 2016 Hugo Willaume
*/

#include	<string.h>
#include	<curses.h>
#include	<strings.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdbool.h>
#include	"misc.h"
#include	"line_edit.h"

extern bool	g_prompt;

static esc_func g_esc_functions[10] =
  {
    go_left,
    go_right,
    word_left,
    word_right,
    start,
    end,
    del,
    destroy_line,
    kill_end,
    NULL
  };

static char	*choose_result(char *result, char c, t_tty *term)
{
  int		lines;

  lines = (strlen(result) + term->prompt_size) / term->width;
  lines -= term->cur_pos.y;
  while (lines > 0)
    {
      my_putchar('\n');
      lines--;
    }
  if (g_prompt == false)
    {
      free(result);
      my_putchar('\n');
      return (strdup("\0"));
    }
  if (c == 4)
    {
      free(result);
      my_putchar('\n');
      return (NULL);
    }
  else
    my_putchar('\n');
  return (result);
}

static void	choose_char(char **result, int *idx, char c, t_tty *term)
{
  char		escape_sequence[20];
  int		idx_cap;

  idx_cap = -1;
  if (c >= ' ' && c < 127)
    {
      write_char(result, idx, c, term);
      if (++term->cur_pos.x == term->width)
	{
	  term->cur_pos.x = 0;
	  term->cur_pos.y++;
	}
      (*idx)++;
    }
  else if (c == 127 && (*idx) > 0)
    del_char((*result), idx, term);
  else if (c != '\n' && c != 4)
    {
      bzero(escape_sequence, 20);
      escape_sequence[0] = c;
      if (c == 27)
	read(0, &escape_sequence[1], 19);
      while (g_esc_functions[++idx_cap] != NULL && g_esc_functions[idx_cap]
	     (result, idx, escape_sequence, term) != 0);
    }
}

static int	get_mallocs(int idx, int *idxsize, char **result)
{
  if (idx == (*idxsize))
    {
      (*idxsize) += 100;
      if (((*result) = realloc((*result), (*idxsize))) == NULL)
	return (1);
      bzero(&(*result)[idx], 100);
    }
  else if (strlen((*result)) != 0 && (*result)[strlen((*result)) - 1] != 0)
    {
      (*idxsize) += 100;
      if (((*result) = realloc((*result), (*idxsize))) == NULL)
	return (1);
      bzero(&(*result)[(*idxsize) - 101], 100);
    }
  return (0);
}

char	*line_edition(t_tty *term)
{
  char	c;
  char	*result;
  int	idx;
  int	idxsize;

  c = 0;
  if ((result = malloc(sizeof(char) * 100)) == NULL)
    return (NULL);
  bzero(result, 100);
  idx = 0;
  idxsize = 99;
  while (c != 4 && c != '\n' && g_prompt == true)
    {
      if (read(0, &c, 1) < 0)
	{
	  free(result);
	  return (NULL);
	}
      choose_char(&result, &idx, c, term);
      if (get_mallocs(idx, &idxsize, &result) != 0)
	return (NULL);
    }
  return (choose_result(result, c, term));
}
