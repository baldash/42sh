/*
** exec.h for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/include/execution
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Mon May 30 22:14:16 2016 teisse_m
** Last update Sun Jun  5 21:16:37 2016 Sylvain Chaugny
*/

#ifndef		EXEC_H_
# define	EXEC_H_

# include	"types/struct_bintree.h"
# include	"prototypes/bintree_functions.h"

void		move_to_the_left(t_binary_list *);
int		move_in_the_tree(t_binary_node *, int *);

#endif		/* !EXEC_H_ */
