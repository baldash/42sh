/*
** misc.h for 42sh in /home/anthony/documents/repository/PSU_2015_minishell2/include
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Fri Apr  1 15:34:37 2016 anthony
** Last update Sun Jun  5 23:08:14 2016 Gabriel Forteville
*/

#ifndef		MISC_H_
# define	MISC_H_

# include	<stddef.h>
# include	<stdbool.h>

# define	IS_CHAR(c, x)	is_separator(c, x)

int		my_putchar(const char c);
void 		my_putstr(const char *str);
int		my_strcompare(char *src1, char *src2);

/*
**		putstr sur stderr
*/

void 		my_perror(const char *str);
void		my_show_wordtab(char **array);
int		prompt(char *);
int		put_error(char *);
int 		my_strlen(const char *str);

/*
**		my_memset: Rempli tous les octets de la zone mémoire mem
**		de taille n de l'octet c.
*/

void		*my_memset(void *mem, size_t n, char c);
char		*my_strdup(const char *s);
char		*modif_strcat(char *, char *);
char		*my_strcpy(char *c, const char *s);
char		*epur_str(char *);
bool		is_separator(char c, const char *separator);
char		**str_to_tab(char *, char);

/*
** Vérification caractère alphanumérique
*/

bool		is_alpha_num(char c);
bool		is_digit(char c);
bool		is_alpha_capital(char c);
bool		is_alpha_min(char c);
bool		is_alpha(char c);
int		is_num(char *);
int		alpha_num(char *);
int		my_getnbr(char *, int, int );

/*
** Manipulation de doubles tableaux
*/

void		free_tab(char **array);
char		**my_tabcpy(char **array);
int		my_tablen(char **array);

#endif		/* !MISC_H_ */
