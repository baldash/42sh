/*
** execution.h for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/include
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Wed Jun 01 22:34:56 2016 Anthony LECLERC
** Last update Sun Jun  5 22:07:19 2016 Sylvain Chaugny
*/

#ifndef			EXECUTION_H_
# define		EXECUTION_H_

# include		"types/struct_bintree.h"
# include		"data.h"

int			execute_new_command(t_binary_build *build, t_data *info);
void			exec_no_path(char **cmd, char **env);
void			check_error_status(int stat);
int			exec_binary_tree(t_binary_list *tree, t_data **info);
void			close_pipes(t_binary_node *root, t_data *info);
void			exit_error(char *);
bool			comma_check(int status);
bool			and_check(int status);
bool			or_check(int status);
int			child_exec(t_binary_node *node, char **env);
int			exec_cmd_line(t_binary_node *root, t_data **);
int			exec_command_line(t_binary_list *tree, t_data **,
					  t_binary_list *);
int			pipe_exec(t_binary_node *node, t_data **info);
int			direct_right_redir(t_binary_node *node, t_data **info);
int			double_right_redir(t_binary_node *node, t_data **info);
int			direct_left_redir(t_binary_node *node, t_data **info);
int			double_left_redir(t_binary_node *node, t_data **info);
int			dup_before_exec(t_binary_node *node);
int			return_error(char *);

#endif			/* !EXECUTION_H_ */
