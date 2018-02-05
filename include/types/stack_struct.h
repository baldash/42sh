/*
** stack_struct.h for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/include/types
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Fri May 27 03:51:21 2016 Anthony LECLERC
** Last update Sun Jun  5 14:39:27 2016 teisse_m
*/

#ifndef			STACK_STRUCT_H_
# define		STACK_STRUCT_H_

# include		"prototypes/errors_parsing.h"

typedef enum		e_noterm
{
  NT_S,
  NT_T,
  NT_E,
  NT_C,
  NT_F,
  NT_G,
  NT_H,
  NT_I,
  NT_J,
  NT_O,
  NT_Q,
  NT_P,
  NT_A,
  NT_W,
  NB_NOTERM,
  IS_TERM = -1
}			t_noterm;

typedef int		(*t_parsing_error)();
typedef int		(*t_insert_node)();

typedef struct		s_stack
{
  struct s_stack	*next;
  t_insert_node		insert_node;
  t_parsing_error	error;
  char			*term;
  int			is_term;
  t_noterm		noterm;
}			t_stack;

void	display_stack_state(t_stack *root);

#endif		/* !STACK_STRUCT_H_ */
