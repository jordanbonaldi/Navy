/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update	Tue Feb 14 13:42:44 2017 Jordan Bonaldi
*/

#ifndef H_CHECK
# define H_CHECK

# define _DEFAULT_SOURCE

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include "lib.h"

typedef struct		s_server
{
  int			pid;
  boolean		haswon;
  boolean		endgame;
  char			**map;
  char			**enemy;
}			t_server;

typedef struct		s_client
{
  int			pid;
  boolean		haswon;
  boolean		endgame;
  char			**map;
  char			**enemy;
}			t_client;

typedef struct		s_boat
{
  int			i;
  int			j;
  char			**boat;
  int			length;
  int			i_max;
  int			j_max;
}			t_boat;

char		my_isnum(char);
char		my_isalpha(char);
boolean		check_win(char **);
boolean		attack_tab(char **, char *, t_string *);
char		*recept_handler();
boolean		send_bin(int, char *);
int		server(char *);
int		client(int, char *);
char		*tobin(int);
char            **create_tab(char *);
t_client	*init_client(int);
t_server	*init_server(int);
char		**init_tab(char **);
int		attack(int, char **, char *, boolean);
int             check_map(char *);
int             ch_bl(char *, int, int);

#endif
