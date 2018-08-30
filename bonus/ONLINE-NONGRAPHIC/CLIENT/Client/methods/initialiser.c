/*
** initialiser.c for initialiser in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 09:48:49 2016 Bonaldi Jordan
** Last update Sat Feb  4 15:30:08 2017 Jordan Bonaldi
*/

# include "project.h"

t_client	*init(int port, char *ip)
{
  t_client	*client;

  if (!(client = malloc(sizeof(*client))) ||
      !(client->enemy = malloc(sizeof(char *) * 11)))
    exit(84);
  client->endgame = false;
  client->enemy = init_tab(client->enemy);
  client->mdp = 0;
  client->ip = ip;
  client->cmdnb = 0;
  create_socket_desc(client);
  set_addr(client, port);
  return (client);
}
