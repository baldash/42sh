/*
** stack.h for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed May 25 01:21:41 2016 Hugo Baldassin
** Last update Sun Jun  5 21:16:20 2016 Sylvain Chaugny
*/

#ifndef		STACK_H_
# define	STACK_H_

# include	"types/stack_struct.h"

/*
** Stack Manipulation
*/

void		pop_stack_elem(t_stack **stack);
int		add_stack_elem(t_stack **stack, t_noterm noterm, const
			       char *term);

/*
** Pour eviter un pop + add
*/

int		replace_top_stack(t_stack *stack, t_noterm noterm, const
				  char *term);
const char	*term_match(t_stack *stack, const char *s);

/*
** get_word
*/

char		*get_word(const char *str);

#endif		/* !STACK_H_ */
