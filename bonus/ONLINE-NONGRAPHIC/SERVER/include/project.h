/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update Sat Feb  4 15:46:39 2017 Jordan Bonaldi
*/

#ifndef H_CHECK
# define H_CHECK

# define _DEFAULT_SOURCE

# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <strings.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <ctype.h>
# include <arpa/inet.h>
# include <netdb.h>
# include "lib.h"

typedef struct		s_server
{
  int                   fd;
  int                   nfd;
  int                   num;
  int                   fs;
  char                  *mdp;
  char                  *ip;
  struct sockaddr_in    local;
  struct sockaddr_in    server;
  char                  *buf;
  char                  *file;
  char                  *filebuf;
  boolean		endgame;
  char			**map;
  char			**enemy;
}			t_server;

char            *receive_message(t_server *);
boolean            send_message(t_server *, char *);
void            my_exit_server(char *);
void            set_addr(t_server *, int);
void            message_handler(t_server *, char *);
void            create_socket_desc(t_server *);
void            wait_connection(t_server *);
t_server        *init(int);

typedef struct		s_boat
{
  int			i;
  int			j;
  char			**boat;
  int			length;
  int			i_max;
  int			j_max;
}			t_boat;

boolean		check_win(char **);
boolean		attack_tab(char **, char *, t_string *);
int		server(int, char *);
char            **create_tab(char *);
char		**init_tab(char **);
int		attack(t_server *, char **, char *, boolean);

#endif
