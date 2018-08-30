/*
** initialiser.c for initialiser in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 09:48:49 2016 Bonaldi Jordan
** Last update Sat Feb  4 15:46:46 2017 Jordan Bonaldi
*/

# include "project.h"

t_server	*init(int port)
{
  t_server	*server;

  if (!(server = malloc(sizeof(*server))) ||
      !(server->enemy = malloc(sizeof(char *) * 11)))
    exit(84);
  server->endgame = false;
  server->enemy = init_tab(server->enemy);
  create_socket_desc(server);
  set_addr(server, port);
  return (server);
}
