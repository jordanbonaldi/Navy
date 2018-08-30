/*
** adress_handler.c for adress_handler in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:08:58 2016 Bonaldi Jordan
** Last update Sun Jan 22 17:09:04 2017 Bonaldi Jordan
*/

# include "project.h"

static void	set_localadress(t_client *cl, int port)
{
  cl->local.sin_family = AF_INET;
  cl->local.sin_port = htons(port);
  inet_pton(AF_INET, cl->ip, &cl->local.sin_addr);
  bzero(&(cl->local.sin_zero), 8);
}

static void	set_connection(t_client *cl, int port)
{
  if (connect(cl->fd, (struct sockaddr *)&cl->local,
	      sizeof(struct sockaddr)) < 0)
    my_exit_cl("ERROR: Failded to connect to the host: ");
  else
    my_printf("[Client] Connected to server at port %d\n", port);
}

void	set_addr(t_client *cl, int port)
{
  set_localadress(cl, port);
  set_connection(cl, port);
}
