/*
** init_structure.c for navy in /home/neferett/EPITECH/PSU_2016_navy
**
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
**
** Started on  Tue Jan 31 01:56:25 2017 Jordan Bonaldi
** Last update Wed Feb  8 16:44:57 2017 Jordan Bonaldi
*/

# include "project.h"

t_server		*init_server(int pid)
{
  t_server		*server;

  if (!(server = malloc(sizeof(*server))) ||
      !(server->enemy = malloc(sizeof(char *) * 11)))
    return (NULL);
  server->endgame = false;
  server->haswon = false;
  server->enemy = init_tab(server->enemy);
  server->pid = pid;
  return (server);
}

t_client		*init_client(int pid)
{
  t_client		*client;

  if (!(client = malloc(sizeof(*client))) ||
      !(client->enemy = malloc(sizeof(char *) * 11)))
    return (NULL);
  client->haswon = false;
  client->endgame = false;
  client->enemy = init_tab(client->enemy);
  client->pid = pid;
  return (client);
}
