/*
** action_table.h for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/include
**
** Made by Anthony LECLEC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Wed May 25 16:04:48 2016 Anthony LECLERC
** Last update Sat May 28 18:30:36 2016 Anthony LECLERC
*/

#ifndef			ACTION_TABLE_H_
# define		ACTION_TABLE_H_
# include		"types/stack_struct.h"
# include		"lexer.h"

typedef int		(*t_action)(t_stack **stack);

extern const t_action	g_action_table[NB_NOTERM][L_MAX_LEXEME];

#endif			/* !ACTION_TABLE_H_ */
