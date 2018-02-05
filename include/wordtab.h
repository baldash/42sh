/*
** wordtab.h for 42sh in /home/sylvain/Documents/zone_tests/PSU/PSU_2015_minishell2/src/ms1
**
** Made by Sylvain Chaugny
** Login   <sylvain@epitech.net>
**
** Started on  Tue Apr  5 21:27:16 2016 Sylvain Chaugny
** Last update Sun Jun  5 23:14:05 2016 Gabriel Forteville
*/

#ifndef		WORDTAB_H_
# define	WORDTAB_H_

typedef struct	s_wordtab
{
  char		**wordtab;
  char		*str;
  char		*limits;
}		t_wordtab;

void		parse_str(t_wordtab		*wt,
			  int			*i,
			  int			*j);
char		**my_str_to_wordtab(char	*str,
				    char	*limits);

#endif		/* !WORDTAB_H_ */
