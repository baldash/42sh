/*
** llparser.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Thu May 26 19:54:57 2016 Anthony LECLERC
** Last update Sun Jun  5 22:53:48 2016 teisse_m
*/

#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>
#include		"parser.h"
#include		"stack.h"
#include		"lexer.h"
#include		"execution.h"
#include		"misc.h"
#include		"rules.h"
#include		"action_table.h"
#include		"prototypes/bintree_functions.h"

/*
** Terminal sur la stack -> match
*/

static int		add_first_list(t_binary_build *trees)
{
  trees->first_list = calloc(1, sizeof(t_binary_list));
  if (trees == NULL)
    {
      my_perror("malloc failed\n");
      return (1);
    }
  trees->cur_list = trees->first_list;
  trees->cur_list->check_if_exec = comma_check;
  trees->cur_list->error_status = 0;
  return (0);
}

static const char	*term_in_stack(const char *s, t_stack **stack,
				       t_binary_build *build, t_lex token)
{
  const char		*p;

  p = term_match(*stack, s);
  if (p == s)
    {
      return (NULL);
    }
  s = p;
  if ((*stack)->insert_node != NULL)
    (*stack)->insert_node(build, (*stack)->term, token);
  pop_stack_elem(stack);
  return (s);
}

/*
** Non terminal sur la Stack
*/

static int		noterm_in_stack(const char *s, t_stack **stack,
					t_lex token)
{
  if ((*stack)->noterm != NT_W)
    {
      if (g_action_table[(*stack)->noterm][token] != NULL)
	{
	  if (g_action_table[(*stack)->noterm][token](stack) != -1)
	    return (0);
	}
    }
  else
    {
      if (rule_37(stack, s) != -1)
	return (0);
    }
  return (1);
}

static int		parser_loop(const char *s, t_stack **stack,
				    t_lex token, t_binary_build *build)
{
  while (*stack != NULL)
    {
      if ((*stack)->term == NULL)
	{
	  if (noterm_in_stack(s, stack, token))
	    return (1);
	}
      else
	{
	  if ((s = term_in_stack(s, stack, build, token)) == NULL)
	    return (1);
	  pass_separator(&s, " \t");
	  token = lexer(0, s);
	}
    }
  return (token != L_END ? 1 : 0);
}

int			llparser(const char *s, t_stack *stack,
				 t_binary_build *build)
{
  t_lex			token;
  int			ret;

  ret = 0;
  pass_separator(&s, " \t&");
  token = lexer(0, s);
  if (token != L_END)
    {
      if (add_first_list(build) == 1)
	return (1);
      add_stack_elem(&stack, NT_S, NULL);
      stack->error = invalid_null_command;
      ret = parser_loop(s, &stack, token, build);
      if (stack != NULL && stack->error != NULL)
	stack->error();
      while (stack != NULL)
	pop_stack_elem(&stack);
      if (build->cur_cmd == NULL || build->main_node == NULL)
	clean_last_command(build);
    }
  return (ret);
}
