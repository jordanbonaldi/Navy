/*
** socket_handler.c for socket_handler in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:16:56 2016 Bonaldi Jordan
** Last update Sat Jan 21 12:54:54 2017 Bonaldi Jordan
*/

# include "project.h"

void	create_socket_desc(t_server *sv)
{
  if ((sv->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    my_exit_server("ERROR: Failed to obtain Socket Descriptor :");
  else
    my_printf("[Server] Socket descriptor obtained successfully.\n");
}

void	wait_connection(t_server *sv)
{
  int	size;

  size = sizeof(struct sockaddr_in);
  if ((sv->nfd = accept(sv->fd,
			(struct sockaddr *)&sv->server, (socklen_t *)&size)) < 0)
    my_exit_server("ERROR: Impossible to obtain new Socket Descriptor :");
  else
    {
      my_printf("[Server] Client is connected with %s.\n",
		inet_ntoa(sv->server.sin_addr));
      sv->ip = my_strdup(inet_ntoa(sv->server.sin_addr));
    }
}
