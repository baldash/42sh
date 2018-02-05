/*
** environnement.h for 42sh in /home/anthony/documents/repository/PSU_2015_minishell2/include
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Tue Apr 12 13:32:28 2016 anthony
** Last update Sun Jun  5 23:14:32 2016 Gabriel Forteville
*/

#ifndef			ENVIRONNEMENT_H_
# define		ENVIRONNEMENT_H_

# include		<stdlib.h>
# include		<stdbool.h>
# include		"data.h"
# include		"struct_bintree.h"

int			exec_builtins(t_binary_node **, t_data *);
void			free_wordtab(char **env);
char			**my_str_to_dot_wordtab(char *str);
size_t			my_wordtab_len(char **tab);
void			my_show_wordtab(char **tab);
char			**env_copy(char **env);
void			my_free_wordtab(char **tab);
bool			is_env_var(const char *env_v, const char *var);
int			is_var_in_environ(const char *variable, char **env);
size_t			get_len_env_var(const char *var);
char			**get_path_wordtab(char **env);
char			*get_env(char **env, const char *key);

#endif			/* !ENVIRONNEMENT_H_ */
