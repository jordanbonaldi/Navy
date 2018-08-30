/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update Sat Feb  4 15:32:19 2017 Jordan Bonaldi
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

typedef struct          s_client
{
  boolean		endgame;
  char			**map;
  char			**enemy;
  int                   fd;
  int                   nfd;
  char                  *ip;
  int                   num;
  int                   cmdnb;
  int                   fs;
  char                  *prompt;
  boolean               mdp;
  struct sockaddr_in    local;
  struct sockaddr_in    server;
  char                  *buf;
  char                  *file;
  char                  *filebuf;
}                       t_client;

void            my_exit_cl(char *);
void            set_addr(t_client *, int);
boolean		send_message(t_client *, char *);
char		*receive_message(t_client *);
void            create_socket_desc(t_client *);
void            wait_connection(t_client *);
t_client        *init(int, char *);

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
int		server(char *);
char		*tobin(int);
char            **create_tab(char *);
t_client	*init_client(int);
int		client(int, char *, char *);
char		**init_tab(char **);
int		attack(t_client *, char **, char *, boolean);

#endif
