/*
** my_str_to_dot_wordtab.c for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/src/execution/environment
**
** Made by Anthony Leclerc
** Login   <lecler_1@epitech.net>
**
** Started on  Sun Jan 24 23:08:53 2016 Anthony Leclerc
** Last update Wed Jun  8 21:19:32 2016 teisse_m
*/

#include	<stdlib.h>

static int	put_word(char **tab, char *str, int tmp, int count)
{
  int		i;

  i = 0;
  while (str[tmp] == ':')
    tmp++;
  while (str[tmp] != ':' && str[tmp] != 0)
    {
      tab[count][i] = str[tmp];
      i++;
      tmp++;
    }
  tab[count][i] = 0;
  return (tmp);
}

static int	malloc_str(char **tab, char *str, int count, int tmp)
{
  int		n;

  n = tmp;
  while (str[n] == ':')
    n++;
  tmp = n;
  while (str[n] != ':' && str[n] != 0)
    n++;
  if ((tab[count] = malloc(n - tmp + 1)) == NULL)
    exit(1);
  tmp = put_word(tab, str, tmp, count);
  return (tmp);
}

static int	count_word(char *str)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      while (str[i] == ':')
	{
	  if (str[i] == '\0')
	    return (count + 1);
	  i++;
	}
      count++;
      while (str[i] != ':' && str[i] != 0)
	i++;
    }
  count -= (str[i - 1] == ' ' || str[i - 1] == '\t') ? 1 : 0;
  return (count + 1);
}

char		**my_str_to_dot_wordtab(char *str)
{
  char		**tab;
  int		count;
  int		tmp;

  if (str == NULL)
    return (NULL);
  tmp = 0;
  count = 0;
  if ((tab = malloc(count_word(str) * sizeof(char *))) == NULL)
    return (NULL);
  while (count < (count_word(str) - 1))
    {
      tmp = malloc_str(tab, str, count, tmp);
      count++;
    }
  tab[count] = NULL;
  return (tab);
}
