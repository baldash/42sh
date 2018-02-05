/*
** lexer.c for PSU_2015_42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing/lexer
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu May 26 17:37:09 2016 Anthony LECLERC
** Last update Fri May 27 03:26:28 2016 Anthony LECLERC
*/

#include		"lexer.h"

static const	t_lexer	g_lexer[] =
{
  is_word,
  get_rdleft,
  get_rleft,
  get_rdright,
  get_rright,
  get_or,
  get_and,
  get_pipe,
  get_comma,
  get_end
};

t_lex			lexer(t_lex lexeme_fct, const char *s)
{
  if (lexeme_fct < L_MAX_LEXEME)
    {
      if (g_lexer[lexeme_fct](s) == 1)
	return (lexeme_fct);
      return (lexer(lexeme_fct + 1, s));
    }
  return (lexeme_fct);
}
