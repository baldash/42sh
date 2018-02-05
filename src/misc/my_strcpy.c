/*
** my_strcpy.c for 42sh in /home/anthony/documents/repository/PSU_2015_minishell2/src/misc
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sun Apr 10 07:25:21 2016 anthony
** Last update Sun Jun  5 22:47:21 2016 teisse_m
*/

char		*my_strcpy(char *c, const char *s)
{
  int		i;

  i = 0;
  while (s[i] != 0)
    {
      c[i] = s[i];
      i++;
    }
  c[i] = 0;
  return (c);
}
