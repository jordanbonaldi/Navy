/*
** server.c for server in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:20:30 2016 Bonaldi Jordan
** Last update Sat Jan 21 19:53:36 2017 Bonaldi Jordan
*/

# include "project.h"

void	server(int port, Boolean mode, char *msg)
{
  t_server	*sv;

  sv = init(port);
  wait_connection(sv);
  while (true)
    {
      if (mode)
	send_file(sv);
      else
	message_handler(sv, msg);
    }
  close(sv->nfd);
}
