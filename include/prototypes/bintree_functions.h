/*
** bintree_functions.h for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/include/prototypes
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Sun May 29 23:44:09 2016 Anthony LECLERC
** Last update Sun Jun  5 21:17:15 2016 Sylvain Chaugny
*/

#ifndef			BINTREE_FUNCTIONS_H_
# define		BINTREE_FUNCTIONS_H_

# include		<unistd.h>
# include		"types/struct_bintree.h"

t_binary_node		*new_node(const char *file,
				  const char *cmd,
				  t_lex type);

/*
**		Arbres de tests
*/

void			display_binary_tree(t_binary_list *tree);
void			clean_last_command(t_binary_build *trees);
void			free_binary_tree(t_binary_list *tree);
t_binary_list		*simple_command();
t_binary_list		*redir_command();

#endif			/* !BINTREE_FUNCTIONS_H_ */
