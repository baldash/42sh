/*
** get_path.c for in /home/anthony/documents/repository/PSU_2015_minishell2/src/environnement
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Tue Apr 12 18:31:17 2016 anthony
** Last update Sun Jun  5 15:34:45 2016 Sylvain Chaugny
*/

#include		"environnement.h"

/*
** If we need a emergency path remplace first NULL by
** "my_str_to_dot_wordtab("/bin:/usr/bin"))"
** Else, do return (NULL);
*/

char			**get_path_wordtab(char **env)
{
  int			i;
  char			*path;

  if ((i = is_var_in_environ("PATH", env)) == -1)
    return (my_str_to_dot_wordtab("/bin:/usr/bin"));
  path = env[i];
  while (*path != '=' && *path != 0)
    path++;
  if (*path == 0 || *(path + 1) == 0)
    return (NULL);
  else
    return (my_str_to_dot_wordtab(path + 1));
}
