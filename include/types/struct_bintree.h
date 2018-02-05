/*
** struct_bintree.h for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/include/types
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Sun May 29 23:03:43 2016 Anthony LECLERC
** Last update Sun Jun  5 20:56:46 2016 Sylvain Chaugny
*/

#ifndef			STRUCT_BINTREE_H_
# define		STRUCT_BINTREE_H_

# include		"lexer.h"
# include		"data.h"

typedef struct		s_binary_node
{
  char			*file;
  char			**cmd;
  int			iofd[2];
  t_lex			operator;
  int			(*op_function)(struct s_binary_node *node, t_data **info);
  struct s_binary_node	*left;
  struct s_binary_node	*right;
  struct s_binary_node	*parent;
}			t_binary_node;

typedef	int		(*t_op_function)(struct s_binary_node *node,
			 t_data **info);

typedef bool		(*t_check_exec)(int status);

typedef struct		s_binary_list
{
  t_check_exec		check_if_exec;
  int			error_status;
  struct s_binary_node	*root;
  struct s_binary_list	*next;
}			t_binary_list;

typedef struct		s_binary_build
{
  struct s_binary_list	*first_list;
  struct s_binary_list	*cur_list;
  struct s_binary_node	*main_node;
  struct s_binary_node	*cur_cmd;
}			t_binary_build;

typedef int		(*op_init_fct)(char **, struct s_binary_node *);

int			line_edit_loop(t_data *info, t_terminals
				       *term, t_binary_build *build);

#endif			/* !STRUCT_BINTREE_H_ */
