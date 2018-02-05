/*
** lexer.h for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/include
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu May 26 17:37:25 2016 Anthony LECLERC
** Last update Sun Jun  5 21:15:03 2016 Sylvain Chaugny
*/

#ifndef		LEXER_H_
# define	LEXER_H_

# include	<stdbool.h>

# define	IS_D_OUT(x)	((x) == L_RDRIGHT) ? true : false
# define	IS_S_OUT(x)	((x) == L_RRIGHT) ? true : false
# define	IS_OUTPUT(x)	(IS_S_OUT(x) || IS_D_OUT(x)) ? true : false
# define	IS_D_IN(x)	((x) == L_RDLEFT) ? true : false
# define	IS_S_IN(x)	((x) == L_RLEFT) ? true : false
# define	IS_INPUT(x)	(IS_S_IN(x) || IS_D_IN(x)) ? true : false

typedef	enum	e_lex
  {
    L_WORD,
    L_RDLEFT,
    L_RLEFT,
    L_RDRIGHT,
    L_RRIGHT,
    L_OR,
    L_AND,
    L_PIPE,
    L_COMMA,
    L_END,
    L_MAX_LEXEME
  }		t_lex;

typedef int	(*t_lexer)(const char *s);

t_lex		lexer(t_lex lexeme, const char *s);

void		pass_separator(const char **s, const char *separator);

int		is_word(const char *s);
int		get_rdleft(const char *s);
int		get_rdright(const char *s);
int		get_rleft(const char *s);
int		get_rright(const char *s);
int		get_or(const char *s);
int		get_and(const char *s);
int		get_pipe(const char *s);
int		get_comma(const char *s);
int		get_end(const char *s);

#endif		/* !LEXER_H_ */
