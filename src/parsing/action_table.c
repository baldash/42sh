/*
** action_table.c for 42sh in /home/anthony/documents/repository/PSU_2015_42sh/src/parsing
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Tue May 24 22:38:01 2016 Anthony LECLERC
** Last update Sun Jun  5 22:52:48 2016 teisse_m
*/

#include	<stddef.h>
#include	"stack.h"
#include	"lexer.h"
#include	"rules.h"
#include	"action_table.h"

/*
** Table des actions permettant de choisir quelle
** règle de grammaire appliquer selon un caractère
** non terminal sur la pile et un caractère terminal
** de la chaîne parsée
** {word, '<<', '<', '>>', '>', '||', '&&', '|', ';', '\0'}
*/

const t_action	g_action_table[NB_NOTERM][L_MAX_LEXEME] =
  {
    {rule_1, rule_1, rule_1, rule_1, rule_1, NULL, NULL, NULL, rule_1,
     eps_rule},
    {rule_8, rule_6, rule_4, rule_5, rule_3, NULL, NULL, NULL, rule_7, NULL},
    {NULL, NULL, NULL, NULL, NULL, rule_10, rule_10, rule_9, rule_10, rule_10},
    {NULL, NULL, NULL, NULL, NULL, rule_12, rule_11, NULL, rule_13, eps_rule},
    {rule_14, rule_16, rule_15, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {rule_17, NULL, NULL, rule_19, rule_18, NULL, NULL, NULL, NULL, NULL},
    {rule_20, rule_21, rule_21, rule_22, rule_22, rule_23,
     rule_23, rule_23, rule_23, rule_23},
    {rule_24, rule_25, rule_25, NULL, NULL, rule_26,
     rule_26, rule_26, rule_26, rule_26},
    {NULL, rule_28, rule_27, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {rule_29, NULL, NULL, rule_30, rule_30,
     rule_31, rule_31, rule_31, rule_31, rule_31},
    {NULL, NULL, NULL, rule_32, rule_33, NULL, NULL, NULL, NULL, NULL},
    {rule_34, NULL, NULL, rule_34, rule_34, NULL, NULL, NULL, NULL, NULL},
    {rule_35, eps_rule, eps_rule, eps_rule, eps_rule,
     eps_rule, eps_rule, eps_rule, eps_rule, eps_rule}
  };
