/*
** parser.h for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Tue May 24 19:58:01 2016 Hugo Baldassin
** Last update Sun Jun  5 23:13:30 2016 Gabriel Forteville
*/

#ifndef		PARSER_H_
# define	PARSER_H_

# include	"types/stack_struct.h"
# include	"types/struct_bintree.h"

int		llparser(const char *s, t_stack *stack, t_binary_build *build);

/*
** Decompose_expression
*/

char		**decompose_expression(char *expr);

/*
** Binary tree manipulations
*/

void		add_up(t_binary_build *trees, t_binary_node *node);
void		add_down_right(t_binary_build *trees, t_binary_node *node);
void		add_down_left(t_binary_build *trees, t_binary_node *node);

int		add_right_redir(t_binary_build *trees, char *elem, t_lex type);
int		add_left_redir(t_binary_build *trees, char *elem, t_lex type);
int		add_pipe(t_binary_build *trees, char *elem, t_lex type);
int		add_cmd(t_binary_build *trees, char *elem, t_lex type);
int		add_file(t_binary_build *trees, char *elem, t_lex type);
int		add_arg(t_binary_build *trees, char *arg, t_lex type);
int		add_first(t_binary_build *trees, char *arg, t_lex type);
int		add_list(t_binary_build *trees, char *arg, t_lex type);

#endif		/* !PARSER_H_ */
