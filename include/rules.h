/*
** rules.h for 42sh in /home/baldas/Prog/repos/psu/PSU_2015_42sh/src/parsing
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu May 26 23:40:58 2016 Hugo Baldassin
** Last update Mon Jun  6 00:32:24 2016 Hugo Baldassin
*/

#ifndef		RULES_H_
# define	RULES_H_

# include	"types/stack_struct.h"

/*
** Initial state rule
*/

int		rule_1(t_stack **stack);

/*
** T state rules (règles parsing de début de commande)
*/

int		rule_3(t_stack **stack);
int		rule_4(t_stack **stack);
int		rule_5(t_stack **stack);
int		rule_6(t_stack **stack);
int		rule_7(t_stack **stack);
int		rule_8(t_stack **stack);

/*
** E state rules (règles de parsing de pipe)
*/

int		rule_9(t_stack **stack);
int		rule_10(t_stack **stack);
int		rule_11(t_stack **stack);
int		rule_12(t_stack **stack);
int		rule_13(t_stack **stack);

/*
** F state rules (règles de parsing de left redirs)
*/

int		rule_14(t_stack **stack);
int		rule_15(t_stack **stack);
int		rule_16(t_stack **stack);

/*
** G state rules (règles de parsing de right redirs)
*/

int		rule_17(t_stack **stack);
int		rule_18(t_stack **stack);
int		rule_19(t_stack **stack);

/*
** H state rules (règles de parsing de multi-redirs)
*/

int		rule_20(t_stack **stack);
int		rule_21(t_stack **stack);
int		rule_22(t_stack **stack);
int		rule_23(t_stack **stack);

/*
** I state rules (règles de parsing d'arguments après left redirs)
*/

int		rule_24(t_stack **stack);
int		rule_25(t_stack **stack);
int		rule_26(t_stack **stack);

/*
** J state rules (règles de parsing de left redirs)
*/

int		rule_27(t_stack **stack);
int		rule_28(t_stack **stack);

/*
** O state rules (règles de parsing d'arguments après right redirs)
*/

int		rule_29(t_stack **stack);
int		rule_30(t_stack **stack);
int		rule_31(t_stack **stack);

/*
** Q state rules (règles de parsing de right redirs)
*/

int		rule_32(t_stack **stack);
int		rule_33(t_stack **stack);

/*
** P state rules (règles de parsing de right redirs)
*/

int		rule_34(t_stack **stack);

/*
** A state rules (règles de parsing d'arguments)
*/

int		rule_35(t_stack **stack);

/*
** Q state rule (règles de parsing de right redirs)
*/

int		rule_37(t_stack **stack, const char *str);

/*
** Eps rule (called at the end of the stack)
*/

int		eps_rule(t_stack **stack);

#endif		/* !RULES_H_ */
