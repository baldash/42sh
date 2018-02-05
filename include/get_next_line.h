/*
** get_next_line.h for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/include
**
** Made by teisse_m
** Login   <teisse_m@epitech.net>
**
** Started on  Tue May 24 18:44:41 2016 teisse_m
** Last update Sun Jun  5 21:14:45 2016 Sylvain Chaugny
*/

#ifndef		GET_NEXT_LINE_H
#define		GET_NEXT_LINE_H

#ifndef		READ_SIZE
# define	READ_SIZE (2048)
#endif		/* !READ_SIZE */

char		*get_next_line(const int, int);
void		buf_free(int flag, char **line, char **buf);
size_t		line_len(char *str);
int		reset_gnl(int flag, char **line, char **buf);

#endif		/* !GET_NEXT_LINE_H */
