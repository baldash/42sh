/*
** get_word.c for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed May 25 19:26:38 2016 Hugo Baldassin
** Last update Sun May 29 23:59:29 2016 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"misc.h"

int		count_word_chars(const char *str)
{
  int		i;

  i = 0;
  while (str[i] && !is_separator(str[i], " |<>&;\t"))
    i++;
  return (i);
}

char		*get_word(const char *str)
{
  int		i;
  int		chars;
  char		*word;

  i = 0;
  chars = count_word_chars(str);
  if (!(word = malloc((chars + 1) * sizeof(char))))
    return (NULL);
  while (str[i] && !is_separator(str[i], " |<>;&\t"))
    {
      word[i] = str[i];
      i++;
    }
  word[i] = '\0';
  return (word);
}
