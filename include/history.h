/*
** history.h for 42sh in /home/teisse_m/rendu/Systeme-Unix/Semestre_2/PSU_2015_42sh/BONUS_Malex
** 
** Made by teisse_m
** Login   <teisse_m@epitech.net>
** 
** Started on  Thu Jun  2 14:22:57 2016 teisse_m
** Last update Sun Jun  5 14:43:53 2016 teisse_m
*/

#ifndef		HISTORY_H_
# define	HISTORY_H_

typedef	struct	s_history
{
  int		line;
  int		history_size;
  char		*path;
  char		**history_tab;
}		t_history;

int		get_path_history(t_history *);
int		update(char *, t_history *);

#endif		/* !HISTORY_H_ */
